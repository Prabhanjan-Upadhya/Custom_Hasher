#include<iostream>
#include<unordered_map>

template <class T>
inline void hash_pair(std::size_t& seed, const T& p){
	std::hash<T> hash_func;
	seed ^= hash_func(p) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename S, typename T> struct std::hash< std::pair<S, T> >{
	inline size_t operator()(const std::pair<S,T>& p) const{
		size_t seed = 0;
		hash_pair(seed, p.first);
		hash_pair(seed, p.second);
		return seed;
	}
};

int main(){
	std::unordered_map< std::pair<int, int>, int> coord { {std::make_pair(2,2), 9} };
	std::cout << coord[std::make_pair(2,2)] << std::endl;
	return 0;
}
