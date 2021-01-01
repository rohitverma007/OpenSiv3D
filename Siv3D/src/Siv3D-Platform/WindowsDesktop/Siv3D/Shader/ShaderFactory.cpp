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

# include <Siv3D/ApplicationOptions.hpp>
# include <Siv3D/Shader/Null/CShader_Null.hpp>
# include <Siv3D/Shader/GL4/CShader_GL4.hpp>
# include <Siv3D/Shader/D3D11/CShader_D3D11.hpp>

namespace s3d
{
	ISiv3DShader* ISiv3DShader::Create()
	{
		if (g_applicationOptions.renderer == EngineOption::Renderer::Headless)
		{
			return new CShader_Null;
		}
		else if (g_applicationOptions.renderer == EngineOption::Renderer::PlatformDefault
			|| g_applicationOptions.renderer == EngineOption::Renderer::Direct3D11)
		{
			return new CShader_D3D11;
		}
		else if (g_applicationOptions.renderer == EngineOption::Renderer::OpenGL)
		{
			return new CShader_GL4;
		}
		else
		{
			return new CShader_Null;
		}
	}
}
