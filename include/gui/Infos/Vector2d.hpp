/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Vector2
*/

#pragma once

template<typename T>
struct vector2d {
	explicit vector2d(T x_value = 0, T y_value = 0) : x(x_value), y(y_value) {}

	bool operator==(const vector2d<T> &v)  { return x == v.x && y == v.y; }

	bool operator!=(const vector2d<T> &v) { return !(*this == v); }

	void operator+=(const T &v) {
		x += v;
		y += v;
	};

	void operator-=(const T &v) {
		x -= v;
		y -= v;
	};

	void operator*=(const T &v) {
		x *= v;
		y *= v;
	};

	void operator/=(const T &v) {
		x /= v;
		y /= v;
	};

	vector2d<T> operator+(const T &v) {
		return vector2d<T>{x + v, y + v};
	}

	vector2d<T> operator-(const T &v) {
		return vector2d<T>{x - v, y - v};
	}

	vector2d<T> operator*(const T &v) {
		return vector2d<T>{x * v, y * v};
	}

	vector2d<T> operator/(const T &v) {
		return vector2d<T>{x / v, y / v};
	}

	void operator-=(const vector2d<T> &v) {
		x -= v.x;
		y -= v.y;
	};

	void operator*=(const vector2d<T> &v) {
		x *= v.x;
		y *= v.y;
	};

	void operator/=(const vector2d<T> &v) {
		x /= v.x;
		y /= v.y;
	};

	vector2d<T> operator+(const vector2d<T> &v) {
		return vector2d<T>{x + v.x, y + v.y};
	}

	vector2d<T> operator-(const vector2d<T> &v) {
		return vector2d<T>{x - v.x, y - v.y};
	}

	vector2d<T> operator*(const vector2d<T> &v) {
		return vector2d<T>{x * v.x, y * v.y};
	}

	vector2d<T> operator/(const vector2d<T> &v) {
		return vector2d<T>{x / v.x, y / v.y};
	}
	T x;
	T y;
};