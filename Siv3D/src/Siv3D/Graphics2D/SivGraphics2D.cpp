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

# include <Siv3D/Graphics2D.hpp>
# include <Siv3D/Renderer2D/IRenderer2D.hpp>
# include <Siv3D/Common/Siv3DEngine.hpp>

namespace s3d
{
	namespace Graphics2D
	{
		Float4 GetColorMul()
		{
			return SIV3D_ENGINE(Renderer2D)->getColorMul();
		}

		Float4 GetColorAdd()
		{
			return SIV3D_ENGINE(Renderer2D)->getColorAdd();
		}

		BlendState GetBlendState()
		{
			return SIV3D_ENGINE(Renderer2D)->getBlendState();
		}

		RasterizerState GetRasterizerState()
		{
			return SIV3D_ENGINE(Renderer2D)->getRasterizerState();
		}

		SamplerState GetSamplerState(const ShaderStage shaderStage, const uint32 slot)
		{
			return SIV3D_ENGINE(Renderer2D)->getSamplerState(shaderStage, slot);
		}

		Optional<VertexShader> GetCustomVertexShader()
		{
			return SIV3D_ENGINE(Renderer2D)->getCustomVS();
		}

		Optional<PixelShader> GetCustomPixelShader()
		{
			return SIV3D_ENGINE(Renderer2D)->getCustomPS();
		}

		const Mat3x2& GetLocalTransform()
		{
			return SIV3D_ENGINE(Renderer2D)->getLocalTransform();
		}

		const Mat3x2& GetCameraTransform()
		{
			return SIV3D_ENGINE(Renderer2D)->getCameraTransform();
		}

		float GetMaxScaling() noexcept
		{
			return SIV3D_ENGINE(Renderer2D)->getMaxScaling();
		}

		void DrawTriangles(const uint32 count)
		{
			SIV3D_ENGINE(Renderer2D)->addNullVertices(count * 3);
		}

		namespace Internal
		{
			void SetColorMul(const Float4& color)
			{
				SIV3D_ENGINE(Renderer2D)->setColorMul(color);
			}

			void SetColorAdd(const Float4& color)
			{
				SIV3D_ENGINE(Renderer2D)->setColorAdd(color);
			}

			void SetBlendState(const BlendState& blendState)
			{
				SIV3D_ENGINE(Renderer2D)->setBlendState(blendState);
			}

			void SetRasterizerState(const RasterizerState& rasterizerState)
			{
				SIV3D_ENGINE(Renderer2D)->setRasterizerState(rasterizerState);
			}

			void SetSamplerState(const ShaderStage shaderStage, const uint32 slot, const SamplerState& samplerState)
			{
				SIV3D_ENGINE(Renderer2D)->setSamplerState(shaderStage, slot, samplerState);
			}

			void SetCustomVertexShader(const Optional<VertexShader>& vs)
			{
				SIV3D_ENGINE(Renderer2D)->setCustomVS(vs);
			}

			void SetCustomPixelShader(const Optional<PixelShader>& ps)
			{
				SIV3D_ENGINE(Renderer2D)->setCustomPS(ps);
			}

			void SetLocalTransform(const Mat3x2& transform)
			{
				SIV3D_ENGINE(Renderer2D)->setLocalTransform(transform);
			}

			void SetCameraTransform(const Mat3x2& transform)
			{
				SIV3D_ENGINE(Renderer2D)->setCameraTransform(transform);
			}
		}
	}
}
