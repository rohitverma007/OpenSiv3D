﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2021 Ryo Suzuki
//	Copyright (c) 2016-2021 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <Siv3D/Common.hpp>
# include <Siv3D/Texture/ITexture.hpp>
# include <Siv3D/AssetHandleManager/AssetHandleManager.hpp>
# include "GL4Texture.hpp"

namespace s3d
{
	class CTexture_GL4 final : public ISiv3DTexture
	{
	private:

		// Texture の管理
		AssetHandleManager<Texture::IDType, GL4Texture> m_textures{ U"Texture" };

	public:

		CTexture_GL4();

		~CTexture_GL4() override;

		void init();

		void updateAsyncTextureLoad(size_t maxUpdate) override;

		Texture::IDType createUnmipped(const Image& image, TextureDesc desc) override;

		Texture::IDType createMipped(const Image& image, const Array<Image>& mips, TextureDesc desc) override;

		void release(Texture::IDType handleID) override;

		Size getSize(Texture::IDType handleID) override;

		TextureDesc getDesc(Texture::IDType handleID) override;

		TextureFormat getFormat(Texture::IDType handleID) override;
	};
}
