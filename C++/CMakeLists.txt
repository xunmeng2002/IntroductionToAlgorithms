#工程名
project(IntroductionToAlgorithms)
enable_language(CXX)
cmake_minimum_required(VERSION 2.8)
if(UNIX)
	add_compile_options(-std=c++11)
	add_definitions(-D LINUX)
	add_compile_options(-g)
endif(UNIX)
#宏定义，添加一个包
#name：是一个不带双引号的字符
#dir：是一个不带引号的路径
macro(add_package name dir)
	include_directories(${dir})
	set(hfind ${ARGV1})
	string(APPEND hfind "/*.h")
	set(cfind ${ARGV1})
	string(APPEND cfind "/*.cpp")
	file(GLOB_RECURSE name_header ${hfind})
	file(GLOB_RECURSE name_cpp ${cfind})
	source_group(${ARGV0} FILES ${name_header} ${name_cpp})
	set(all_file ${all_file} ${name_header} ${name_cpp})
endmacro(add_package)


add_package(Src ./Src)
add_package(Chapter2 ./Chapter2)
add_package(Chapter4 ./Chapter4)
add_package(Chapter6 ./Chapter6)
add_package(Chapter7 ./Chapter7)
add_package(Chapter8 ./Chapter8)
add_package(Chapter9 ./Chapter9)

add_definitions("-D_CRT_SECURE_NO_WARNINGS")


#添加工程
add_executable(IntroductionToAlgorithms ${all_file})

