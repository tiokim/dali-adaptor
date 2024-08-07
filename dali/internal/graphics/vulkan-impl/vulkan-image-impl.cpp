/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <dali/internal/graphics/vulkan/vulkan-device.h>
#include <dali/internal/graphics/vulkan-impl/vulkan-image-impl.h>
#include <dali/internal/graphics/vulkan-impl/vulkan-memory-impl.h>
#include <dali/integration-api/debug.h>

#if defined(DEBUG_ENABLED)
extern Debug::Filter* gVulkanFilter;
#endif


namespace Dali
{
namespace Graphics
{
namespace Vulkan
{

Image::Image( Device& graphicsDevice, const vk::ImageCreateInfo& createInfo, vk::Image externalImage )
: mGraphicsDevice( &graphicsDevice ),
  mCreateInfo( createInfo ),
  mImage( externalImage ),
  mImageLayout( mCreateInfo.initialLayout ),
  mIsExternal( static_cast<bool>(externalImage) )
{
  auto depthStencilFormats = std::vector< vk::Format >{
          vk::Format::eD32Sfloat,
          vk::Format::eD16Unorm,
          vk::Format::eD32SfloatS8Uint,
          vk::Format::eD24UnormS8Uint,
          vk::Format::eD16UnormS8Uint,
          vk::Format::eS8Uint,
  };

  auto hasDepth = std::find( depthStencilFormats.begin(), depthStencilFormats.end(), createInfo.format );

  if( hasDepth != depthStencilFormats.end() )
  {
    auto format = *hasDepth;

    if( format == vk::Format::eD32Sfloat || format == vk::Format::eD16Unorm )
    {
      mAspectFlags = vk::ImageAspectFlagBits::eDepth;
    }
    else if( format == vk::Format::eS8Uint )
    {
      mAspectFlags = vk::ImageAspectFlagBits::eStencil;
    }
    else
    {
      mAspectFlags = vk::ImageAspectFlagBits::eDepth | vk::ImageAspectFlagBits::eStencil;
    }
  }
  else
  {
    mAspectFlags = vk::ImageAspectFlagBits::eColor;
  }
}

vk::Image Image::GetVkHandle() const
{
  return mImage;
}

vk::ImageLayout Image::GetImageLayout() const
{
  return mImageLayout;
}

uint32_t Image::GetWidth() const
{
  return mCreateInfo.extent.width;
}

uint32_t Image::GetHeight() const
{
  return mCreateInfo.extent.height;
}

uint32_t Image::GetLayerCount() const
{
  return mCreateInfo.arrayLayers;
}

uint32_t Image::GetMipLevelCount() const
{
  return mCreateInfo.mipLevels;
}

vk::Format Image::GetFormat() const
{
  return mCreateInfo.format;
}

vk::ImageType Image::GetImageType() const
{
  return mCreateInfo.imageType;
}

vk::ImageTiling Image::GetImageTiling() const
{
  return mCreateInfo.tiling;
}

vk::ImageAspectFlags Image::GetAspectFlags() const
{
  return mAspectFlags;
}

void Image::SetImageLayout( vk::ImageLayout imageLayout )
{
  mImageLayout = imageLayout;
}

const Image& Image::ConstRef()
{
  return *this;
}

Image& Image::Ref()
{
  return *this;
}

vk::ImageUsageFlags Image::GetUsageFlags() const
{
  return mCreateInfo.usage;
}

vk::SampleCountFlagBits Image::GetSampleCount() const
{
  return mCreateInfo.samples;
}

void Image::DestroyNow()
{
  DestroyVulkanResources(mGraphicsDevice->GetLogicalDevice(), mImage, mDeviceMemory->ReleaseVkObject(),
       &mGraphicsDevice->GetAllocator() );
  mImage = nullptr;
  mDeviceMemory = nullptr;
}

bool Image::OnDestroy()
{
  if( !mIsExternal )
  {
    if( mImage )
    {
      auto device = mGraphicsDevice->GetLogicalDevice();
      auto image = mImage;
      auto allocator = &mGraphicsDevice->GetAllocator();
      auto memory = mDeviceMemory->ReleaseVkObject();

      mGraphicsDevice->DiscardResource( [ device, image, memory, allocator ]() {
        DestroyVulkanResources( device, image, memory, allocator );
      }
      );
    }
  }

  return false;
}

void Image::DestroyVulkanResources( vk::Device device, vk::Image image, vk::DeviceMemory memory, const vk::AllocationCallbacks* allocator )
{
  DALI_LOG_INFO( gVulkanFilter, Debug::General, "Invoking deleter function: image->%p\n",
                 static_cast< VkImage >(image) )
  device.destroyImage( image, allocator );

  device.freeMemory( memory, allocator );
}


} // namespace Vulkan

} // namespace Graphics

} // namespace Dali
