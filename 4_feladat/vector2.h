#include <iostream>
#include <string>
#include <cmath>

template<typename T>
struct vec2{
    T x, y;

    vec2<T>& operator=(vec2<T> const& v){
        x = v.x;
        y = v.y;
        return *this;
    }

    template<typename T1>
    auto& operator+=(vec2<T1> const& v){
        x += v.x;
        y += v.y;
        return *this;
    }

    template<typename T1>
    auto& operator-=(vec2<T1> const& v){
        x -= v.x;
        y -= v.y;
        return *this;
    }

    template<typename T1>
    auto& operator*=(T1 const& c){
        x *= c;
        y *= c;
        return *this;
    }

    template<typename T1>
    auto& operator/=(T1 const& d){
        x /= d;
        y /= d;
        return *this;
    }
};

template<typename T1, typename T2>
auto operator+(vec2<T1> const& v1,vec2<T2> const& v2){
    return vec2<decltype(v1.x+v2.x)>{v1.x+v2.x,v1.y+v2.y};
}

template<typename T1, typename T2>
auto operator-(vec2<T1> const& v1,vec2<T2> const& v2){
    return vec2<decltype(v1.x-v2.x)>{v1.x-v2.x,v1.y-v2.y};
}

template<typename T1, typename T2>
auto operator*(T1 const& c,vec2<T2> const& v){
    return vec2<decltype(c * v.x)>{c * v.x, c * v.y};
}

template<typename T1, typename T2>
auto operator*(vec2<T1> const& v, T2 const& c){
    return vec2<decltype(c * v.x)>{c * v.x, c * v.y};
}

template<typename T1, typename T2>
auto operator/(vec2<T1> const& v, T2 const& d){
    return vec2<decltype(v.x / d)>{v.x / d , v.y / d};
}

template<typename T>
std::ostream& operator<<(std::ostream& o,vec2<T> const& v){
    o<<"["<<v.x<<", "<<v.y<<"]";
    return o;
}

template<typename T>
std::istream& operator>>(std::istream& i,vec2<T>& v){
    i>>v.x;
    i>>v.y;
    return i;
}

template<typename T1,typename T2>
auto dot(vec2<T1> const& v1, vec2<T2> const& v2){
    return v1.x * v2.x + v1.y * v2.y;
}

template<typename T>
auto length(vec2<T> const& v){
    return std::sqrt(dot(v, v));
}

template<typename T>
auto sqlength(vec2<T> const& v){
    return dot(v, v);
}

template<typename T>
vec2<T> normalize(vec2<T> const& v){
    double l = length(v);
    if(l < 1e-12){
        std::cout<<"Vector is a null vector!"<<std::endl;
        return v;
    }
    return v / l;
}

template<typename T1, typename T2>
bool operator==(vec2<T1> const& v1, vec2<T2> const& v2){
    double eps = 1e-10;
    if(std::abs(v1.x - v2.x) < eps && std::abs(v1.y -v2.y) < eps){
        return true;
    }
    return false;
}

template<typename T1, typename T2>
bool operator!=(vec2<T1> const& v1, vec2<T2> const& v2){
    return !(v1==v2);
}
