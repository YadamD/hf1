#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <initializer_list>
#include <cmath>
#include <ostream>

namespace detail{
	template<typename M1, typename M2, typename F>
	void transform_matrix1(M1 const& m1, M2& m2, F f){
		std::transform(m1.cbegin(), m1.cend(), m2.begin(), f);
	}

	template<typename M1, typename M2, typename M3, typename F>
	void transform_matrix2(M1 const& m1, M2 const& m2, M3 & m3, F f){
		std::transform(m1.cbegin(), m1.cend(), m2.cbegin(), m3.begin(), f);
	}
}

auto add = [](auto const& x, auto const& y){ return x + y; };
auto sub = [](auto const& x, auto const& y){ return x - y; };

template<typename T>
class sq_matrix{

    int dim;
    std::vector<T> data;

    public:

    sq_matrix(): dim{1}, data{{0.0}}{};
    sq_matrix(int i): dim{i}, data(i*i,0){};
    sq_matrix(int i, std::vector<T> v): dim{i} {
        if(dim * dim == static_cast<int>(v.data.size())){
            data(v);
        }
        else{
            std::cout<<"Initialization error!"<<std::endl;
            exit(-1);
        }
    };
    sq_matrix<T>(sq_matrix<T> const& cpy): dim{cpy.dim}, data{cpy.data}{
        if( dim != cpy.n){
            std::cout<<"Dimension error!"<<std::endl;
            exit(-1);
        }
    }

	sq_matrix(sq_matrix&&) = default;
	sq_matrix<T>& operator=(sq_matrix&&) = default;
    T & operator()(int i, int j){return data[dim * i + j];}
    T const& operator()(int i, int j) const {return data[ dim * i + j];}

    int dimension() const{
		return dim;
	}

    int size() const{
		return dim*dim;
	}
    std::vector<T> get_data() const&{
		return data;
	}
    std::vector<T> set_data(){
		return data;
	}

	auto begin(){
		return data.begin();
	}

	auto cbegin() const{
		return data.cbegin();
	}

	auto end(){
		return data.end();
	}

	auto cend() const{
		return data.cend();
    }
    
    sq_matrix(std::initializer_list<T> const& list){
        double dim_check = sqrt(static_cast<int>(list.size()));
        int dim_check_int = static_cast<int>(dim_check);
        if(dim_check - dim_check_int  > 1e-10){
            std::cout<<"Error: nonsquare matrix!"<<std::endl;
            exit(-1);
        }
        dim = static_cast<int>(dim_check);
        data = list;
    };
    sq_matrix<T>& operator=(std::initializer_list<T> const& list){
        double dim_check = sqrt(static_cast<int>(list.size()));
        int dim_check_int = static_cast<int>(dim_check);
        if(dim_check - dim_check_int  > 1e-10){
            std::cout<<"Error: nonsquare matrix!"<<std::endl;
            exit(-1);
        }
        dim = static_cast<int>(dim_check);
        data = list;
    };

    template<typename T1>
    friend sq_matrix<T1>&& operator+(sq_matrix<T1>&& m1, sq_matrix<T1> const& m2);
    template<typename T1>
    friend sq_matrix<T1> operator+(sq_matrix<T1> const& m1, sq_matrix<T1> const& m2);
    template<typename T1>
    friend sq_matrix<T1> sq_mat_mul(sq_matrix<T1> const& m1, sq_matrix<T1> const& m2);
    template<typename T1>
    friend std::ostream& operator<<(std::ostream& o, sq_matrix<T1> const& m);
    template<typename T1>
    friend sq_matrix<T1> operator-(sq_matrix<T1> const& m1, sq_matrix<T1> const& m2);
};

template<typename T>
sq_matrix<T> operator+(sq_matrix<T> const& m1, sq_matrix<T> const& m2){
    sq_matrix<T> result(m1.dimension());
    detail::transform_matrix2(m1.data, m2.data, result.data, add);
    return result;
}

template<typename T>
sq_matrix<T>&& operator+(sq_matrix<T>&& m1, sq_matrix<T> const& m2){
    detail::transform_matrix1(m1.data, m2.data, m1.data, add);
    return std::move(m1);
}

template<typename T>
sq_matrix<T>&& operator+(sq_matrix<T> const& m1, sq_matrix<T>&& m2){
    detail::transform_matrix2(m1.data, m2.data, m1.data, add);
    return std::move(m2);
}

template<typename T>
sq_matrix<T> && operator+(sq_matrix<T>&& m1, sq_matrix<T>&& m2){
    detail::transform_matrix2(m1.data, m2.data, m1.data, add);
    return std::move(m1);
}

template<typename T>
sq_matrix<T> operator-(sq_matrix<T> const& m1, sq_matrix<T> const& m2){
    sq_matrix<T> result(m1.dimension());
    detail::transform_matrix2(m1.get_data(), m2.get_data(), result.data, sub);
    return result;
}

template<typename T>
sq_matrix<T>&& operator-(sq_matrix<T>&& m1, sq_matrix<T> const& m2){
    detail::transform_matrix2(m1.data, m2.data, m1.data, sub);
    return std::move(m1);
}

template<typename T>
sq_matrix<T>&& operator-(sq_matrix<T> const& m1, sq_matrix<T>&& m2){
    detail::transform_matrix2(m1.data, m2.data, m1.data, sub);
    return std::move(m2);
}

template<typename T>
sq_matrix<T>&& operator-(sq_matrix<T>&& m1, sq_matrix<T>&& m2){
    detail::transform_matrix2(m1.data, m2.data, m1.data, sub);
    return std::move(m1);
}

template<typename T>
sq_matrix<T> operator*(sq_matrix<T> const& m, T const& c){
    sq_matrix<T> result;
    result.data.resize(m.len);
    detail::transform_matrix1(m.data, result.data, [c](T const& x){return x * c;});
    return result;
}

template<typename T>
sq_matrix<T> && operator*(sq_matrix<T>&& m, T const& c){
    detail::transform_matrix1(m.data, m.data, [c](T const& x){return x * c;});
    return std::move(m);
}

template<typename T>
sq_matrix<T> operator*(T const& c, sq_matrix<T> const& m){
    sq_matrix<T> result;
    result.data.resize(m.len);
    detail::transform_matrix1(m.data, result.data, [c](T const& x){return x * c;});
    return result;
}

template<typename T>
sq_matrix<T>&& operator*(T const& c, sq_matrix<T>&& m){
    detail::transform_matrix1(m.data, m.data, [c](T const& x){return x * c;});
    return std::move(m);
}

template<typename T1, typename T2>
sq_matrix<T1> operator/(sq_matrix<T1> const& m, T2 const& c){
    sq_matrix<T1> result;
    result.data.resize(m.len);
    detail::transform_matrix1(m.data, result.data, [c](T1 const& x){return x / c;});
    return result;
}

template<typename T1, typename T2>
sq_matrix<T1>&& operator/(sq_matrix<T1>&& m, T2 const& c){
    detail::transform_matrix1(m.data, m.data, [c](T1 const& x){return x / c;});
}

template<typename T>
sq_matrix<T> sq_mat_mul(sq_matrix<T> const& m1, sq_matrix<T> const& m2){
    int const n = m1.dimension();
    double sum = 0;
    sq_matrix<T> temp(m1.dimension());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum = 0;
            for(int k = 0; k < n; k++){
                sum += (m1.data[i * n + k]) * (m2.data[k * n + j ]);
            }
        temp.data[n*i+j] = sum;
        }
    }
    return temp;
}

template<typename T>
sq_matrix<T> operator*(sq_matrix<T> const& m1, sq_matrix<T> const& m2){  
    return sq_mat_mul(m1, m2);
}

template<typename T1>
sq_matrix<T1>&& operator*(sq_matrix<T1>&& m1, sq_matrix<T1> const& m2){
    sq_matrix<T1> m1 = sq_mat_mul(m1, m2);
    return std::move(m1);
}

template<typename T1>
sq_matrix<T1>&& operator*(sq_matrix<T1> const& m1, sq_matrix<T1>&& m2){
    sq_matrix<T1> m2 = sq_mat_mul(m1, m2);
    return std::move(m2);
}

template<typename T>
std::ostream& operator<<(std::ostream& o, sq_matrix<T> const& m){
	int n = {m.dimension()};
		for(int i = 0; i < n; i++){
            o<<" ";
            for(int j = 0 ; j < n; j++){
                o<<m(i,j)<<" ";
            }
            o<<"\n";
		}
	return o;
}

template<typename T>
bool sq_matrix_eq(sq_matrix<T> const& m1, sq_matrix<T> const& m2, double eps){
    int n = m1.dimension();
    if(n != m2.dimension()){
        return false;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(std::abs(m1(i,j) - m2(i,j)) > eps){
                return false;
            }
        }
    }
    return true;
}
