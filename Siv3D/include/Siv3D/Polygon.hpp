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
# include "Common.hpp"
# include "PointVector.hpp"
# include "ColorHSV.hpp"
# include "PolygonFailureType.hpp"
# include "Vertex2D.hpp"
# include "2DShapes.hpp"
# include "TriangleIndex.hpp"
# include "PredefinedYesNo.hpp"

namespace s3d
{
	class Shape2D;

	class Polygon
	{
	private:

		class PolygonDetail;

	public:

		Polygon();

		Polygon(const Polygon& polygon);

		Polygon(Polygon&& polygon) noexcept;

		Polygon(const Vec2* outer, size_t size, Array<Array<Vec2>> holes = {}, SkipValidation skipValidation = SkipValidation::No);

		explicit Polygon(const Array<Vec2>& outer, Array<Array<Vec2>> holes = {}, SkipValidation skipValidation = SkipValidation::No);

		Polygon(const Array<Vec2>& outer, const Array<TriangleIndex>& indices, const RectF& boundingRect, SkipValidation skipValidation = SkipValidation::No);

		Polygon(const Array<Vec2>& outer, Array<Array<Vec2>> holes, const Array<Float2>& vertices, const Array<TriangleIndex>& indices, const RectF& boundingRect, SkipValidation skipValidation = SkipValidation::No);

		explicit Polygon(std::initializer_list<Vec2> outer, SkipValidation skipValidation = SkipValidation::No);

		Polygon(const Shape2D& shape);

		~Polygon();

		Polygon& operator =(const Polygon& polygon);

		Polygon& operator =(Polygon&& polygon) noexcept;

		[[nodiscard]]
		bool isEmpty() const noexcept;

		[[nodiscard]]
		explicit operator bool() const noexcept;

		[[nodiscard]]
		bool hasHoles() const noexcept;

		[[nodiscard]]
		size_t num_holes() const noexcept;

		void swap(Polygon& polygon) noexcept;

		[[nodiscard]]
		const Array<Vec2>& outer() const noexcept;

		[[nodiscard]]
		const Array<Array<Vec2>>& inners() const noexcept;

		[[nodiscard]]
		const Array<Float2>& vertices() const noexcept;

		[[nodiscard]]
		const Array<TriangleIndex>& indices() const noexcept ;

		[[nodiscard]]
		const RectF& boundingRect() const noexcept;

		[[nodiscard]]
		size_t num_triangles() const noexcept;

		[[nodiscard]]
		Triangle triangle(size_t index) const;

		Polygon& addHole(Array<Vec2> hole, SkipValidation skipValidation = SkipValidation::No);

		Polygon& addHoles(Array<Array<Vec2>> holes, SkipValidation skipValidation = SkipValidation::No);

		[[nodiscard]]
		Polygon movedBy(double x, double y) const;

		[[nodiscard]]
		Polygon movedBy(Vec2 v) const;

		Polygon& moveBy(double x, double y) noexcept;

		Polygon& moveBy(Vec2 v) noexcept;

		/*
		[[nodiscard]] Polygon rotated(double angle) const;

		[[nodiscard]] Polygon rotatedAt(double x, double y, double angle) const;

		[[nodiscard]] Polygon rotatedAt(const Vec2& pos, double angle) const;

		Polygon& rotate(double angle);

		Polygon& rotateAt(double x, double y, double angle);

		Polygon& rotateAt(const Vec2& pos, double angle);

		[[nodiscard]] Polygon transformed(double s, double c, const Vec2& pos) const;

		Polygon& transform(double s, double c, const Vec2& pos);

		[[nodiscard]] Polygon scaled(double s) const;

		Polygon& scale(double s);

		[[nodiscard]] Polygon scaled(const Vec2& s) const;

		Polygon& scale(const Vec2& s);
		*/

		[[nodiscard]]
		double area() const noexcept;

		[[nodiscard]]
		double perimeter() const noexcept;

		[[nodiscard]]
		Vec2 centroid() const;

		[[nodiscard]]
		Polygon calculateConvexHull() const;

		[[nodiscard]]
		Polygon calculateBuffer(double distance) const;

		[[nodiscard]]
		Polygon calculateRoundBuffer(double distance) const;

		[[nodiscard]]
		Polygon simplified(double maxDistance = 2.0) const;

		/*
		bool append(const Polygon& polygon);
		*/

		/*
		template <class Shape2DType>
		[[nodiscard]] bool intersects(const Shape2DType& shape) const
		{
			return Geometry2D::Intersect(*this, shape);
		}

		[[nodiscard]] bool intersects(const Polygon& polygon) const;

		template <class Shape2DType>
		[[nodiscard]] Optional<Array<Vec2>> intersectsAt(const Shape2DType& shape) const
		{
			return Geometry2D::IntersectAt(*this, shape);
		}

		template <class Shape2DType>
		[[nodiscard]] bool contains(const Shape2DType& shape) const
		{
			return Geometry2D::Contains(*this, shape);
		}
		*/

		/*
		[[nodiscard]] bool leftClicked() const;

		[[nodiscard]] bool leftPressed() const;

		[[nodiscard]] bool leftReleased() const;

		[[nodiscard]] bool rightClicked() const;

		[[nodiscard]] bool rightPressed() const;

		[[nodiscard]] bool rightReleased() const;

		[[nodiscard]] bool mouseOver() const;
		*/

		/*
		const Polygon& paint(Image& dst, const Color& color) const;

		const Polygon& paint(Image& dst, double x, double y, const Color& color) const;

		const Polygon& paint(Image& dst, const Vec2& pos, const Color& color) const;

		const Polygon& overwrite(Image& dst, const Color& color, bool antialiased = true) const;

		const Polygon& overwrite(Image& dst, double x, double y, const Color& color, bool antialiased = true) const;

		const Polygon& overwrite(Image& dst, const Vec2& pos, const Color& color, bool antialiased = true) const;
		*/

		const Polygon& draw(const ColorF& color = Palette::White) const;

		//void draw(double x, double y, const ColorF& color = Palette::White) const;

		//void draw(cons Vec2& pos, const ColorF& color = Palette::White) const;

		const Polygon& drawFrame(double thickness = 1.0, const ColorF& color = Palette::White) const;

		//void drawFrame(double x, double y, double thickness = 1.0, const ColorF& color = Palette::White) const;

		//void drawFrame(cons Vec2& pos, double thickness = 1.0, const ColorF& color = Palette::White) const;

		const Polygon& drawWireframe(double thickness = 1.0, const ColorF& color = Palette::White) const;

		//void drawWireframe(double x, double y, double thickness = 1.0, const ColorF& color = Palette::White) const;

		//void drawWireframe(cons Vec2& Vec2 pos, double thickness = 1.0, const ColorF& color = Palette::White) const;

		//void drawTransformed(double s, double c, cons Vec2& pos, const ColorF& color = Palette::White) const;

		//[[nodiscard]]
		//static PolygonFailureType Validate(const Float2* pVertex, size_t vertexSize, const Array<Array<Vec2>>& holes = {});

		//[[nodiscard]]
		//static PolygonFailureType Validate(const Array<Float2>& vertices, const Array<Array<Vec2>>& holes = {});

		[[nodiscard]]
		static PolygonFailureType Validate(const Vec2* pVertex, size_t vertexSize, const Array<Array<Vec2>>& holes = {});

		[[nodiscard]]
		static PolygonFailureType Validate(const Array<Vec2>& vertices, const Array<Array<Vec2>>& holes = {});

		//[[nodiscard]]
		//static Array<Polygon> Correct(const Vec2* pVertex, size_t vertexSize, const Array<Array<Vec2>>& holes = {});

		//[[nodiscard]]
		//static Array<Polygon> Correct(const Array<Vec2>& vertices, const Array<Array<Vec2>>& holes = {});

		[[nodiscard]]
		const PolygonDetail* _detail() const noexcept;

	private:

		class PolygonDetail;

		std::unique_ptr<PolygonDetail> pImpl;
	};

	inline void swap(Polygon& a, Polygon& b) noexcept;
}

template <>
inline void std::swap(s3d::Polygon& a, s3d::Polygon& b) noexcept;

# include "detail/Polygon.ipp"
