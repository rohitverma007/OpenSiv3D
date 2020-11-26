﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2020 Ryo Suzuki
//	Copyright (c) 2016-2020 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <Siv3D/Common.hpp>
# include <Siv3D/Common/OpenGL.hpp>
# include <Siv3D/BlendState.hpp>
# include <Siv3D/HashTable.hpp>

namespace s3d
{
	class GLES3BlendState
	{
	private:

		BlendState m_currentState = BlendState::Default;

	public:

		GLES3BlendState();

		void set(const BlendState& state);
	};
}
