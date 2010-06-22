
/*
    Copyright (C)  2010  Marius Stoica

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#define ENUM_INT int_enum_t
#define ENUM_PROPERTIES


#ifndef ENUM_HPP
#define ENUM_HPP


// #pragma message PP_STRINGIZE(( ENUM_BEGIN ))
// #pragma message PP_STRINGIZE(ENUM_END)
// #pragma message PP_STRINGIZE(ENUM_CLASS)
// #pragma message PP_STRINGIZE(ENUM_VALUES)
// #pragma message PP_STRINGIZE(ENUM_ADJECTIVE)
// #pragma message PP_STRINGIZE(ENUM_PROPERTIES)


#include <boost/algorithm/string/replace.hpp>

#include <boost/preprocessor/cat.hpp>
#define PP_CAT BOOST_PP_CAT

#include <boost/preprocessor/seq/seq.hpp>
#define PP_SEQ_HEAD BOOST_PP_SEQ_HEAD
#define PP_SEQ_TAIL BOOST_PP_SEQ_TAIL

#include <boost/preprocessor/seq/enum.hpp>
#define PP_SEQ_ENUM BOOST_PP_SEQ_ENUM

#include <boost/preprocessor/control/iif.hpp>
#define PP_IIF BOOST_PP_IIF

#include <boost/preprocessor/seq/for_each.hpp>
#define PP_SEQ_FOR_EACH BOOST_PP_SEQ_FOR_EACH

#include <boost/preprocessor/stringize.hpp>
#define PP_STRINGIZE BOOST_PP_STRINGIZE



template<class T,class TEnum>
class Enum
{
    public:
	Enum(TEnum a):value{a} {};
	Enum() = delete;
	Enum operator=(const Enum&) = delete;
	
	operator TEnum() const {
	    return value;
	}
	friend bool operator==(const T a, const T b) {
	    return (TEnum)a == (TEnum)b;
	}
	friend bool operator!=(const T a, const T b) {
	    return (TEnum)a != (TEnum)b;
	}
	friend bool operator==(const T a, const TEnum b) {
	    return (TEnum)a == b;
	}
	friend bool operator==(const TEnum a, const T b) {
	    return a == (TEnum)b;
	}
	friend bool operator!=(const T a, const TEnum b) {
	    return (TEnum)a != b;
	}
	friend bool operator!=(const TEnum a, const T b) {
	    return a != (TEnum)b;
	}
	
	operator std::string() const {
	    static_assert(sizeof(TEnum) <= sizeof(int32_t),"truncated casting");
	    return T::stringmap[(int32_t)operator TEnum()];
	}
	friend std::string operator+(const std::string& s, const T t) {
	    return s + (std::string)t;
	}
	friend std::string operator+(const T t, const std::string& s) {
	    return (std::string)t + s;
	}
	friend std::string operator+(const String s, const T t) {
	    return s + (std::string)t;
	}
	friend std::string operator+(const T t, const String s) {
	    return (std::string)t + s;
	}
	
	String _Adjective() const {
	    return adjective;
	}
	String _Classname() const {
	    return classname;
	}
    protected:
	TEnum value;
	static const bool init_map;
	static const String adjective;
	static const String classname;
};

template<class T,class TEnum>
class Comparable
{
    public:
	static_assert(sizeof(TEnum) <= sizeof(int32_t),"truncated casting");
	friend bool operator>(T a, T b) {
	    return (int32_t)(TEnum)a > (int32_t)(TEnum)b;
	}
	friend bool operator>=(T a, T b) {
	    return (int32_t)(TEnum)a >= (int32_t)(TEnum)b;
	}
	friend bool operator<(T a, T b) {
	    return (int32_t)(TEnum)a < (int32_t)(TEnum)b;
	}
	friend bool operator<=(T a, T b) {
	    return (int32_t)(TEnum)a <= (int32_t)(TEnum)b;
	}
	
	
	friend bool operator>(T a, TEnum b) {
	    return (int32_t)(TEnum)a > (int32_t)b;
	}
	friend bool operator>=(T a, TEnum b) {
	    return (int32_t)(TEnum)a >= (int32_t)b;
	}
	friend bool operator<(T a, TEnum b) {
	    return (int32_t)(TEnum)a < (int32_t)b;
	}
	friend bool operator<=(T a, TEnum b) {
	    return (int32_t)(TEnum)a <= (int32_t)b;
	}
	
	
	friend bool operator>(TEnum a, T b) {
	    return (int32_t)a > (int32_t)(TEnum)b;
	}
	friend bool operator>=(TEnum a, T b) {
	    return (int32_t)a >= (int32_t)(TEnum)b;
	}
	friend bool operator<(TEnum a, T b) {
	    return (int32_t)a < (int32_t)(TEnum)b;
	}
	friend bool operator<=(TEnum a, T b) {
	    return (int32_t)a <= (int32_t)(TEnum)b;
	}
	
	
	friend bool operator>(TEnum a, TEnum b) {
	    return (int32_t)a > (int32_t)b;
	}
	friend bool operator>=(TEnum a, TEnum b) {
	    return (int32_t)a >= (int32_t)b;
	}
	friend bool operator<(TEnum a, TEnum b) {
	    return (int32_t)a < (int32_t)b;
	}
	friend bool operator<=(TEnum a, TEnum b) {
	    return (int32_t)a <= (int32_t)b;
	}
};



#define PP_VOID


#define ENUM_EXPAND_PROPERTIES_MACRO(r, data, elem) 		\
	public elem<ENUM_CLASS,PP_CAT( T, ENUM_CLASS)>,


#define ENUM_EXPAND_PROPERTIES( enums ) 			\
	PP_SEQ_FOR_EACH(ENUM_EXPAND_PROPERTIES_MACRO, ~, enums)




#define ENUM_EXPAND_ENUM_MACRO(r, data, elem)			\
	( PP_SEQ_HEAD(elem)					\
	  PP_IIF( BOOST_PP_SEQ_SIZE( PP_SEQ_TAIL(elem)),	\
		PP_SEQ_HEAD(PP_SEQ_TAIL(elem)()),		\
		PP_VOID						\
	  ) )


#define ENUM_EXPAND_ENUM( enums ) 				\
PP_SEQ_ENUM ( 							\
	PP_SEQ_FOR_EACH(ENUM_EXPAND_ENUM_MACRO, ~, enums)	\
	)



#define ENUM_EXPAND_VALUES_MACRO(r, data, elem) 		\
(	PP_SEQ_HEAD(elem) = 					\
	PP_CAT( T, ENUM_CLASS)::PP_SEQ_HEAD(elem)		\
)


#define ENUM_EXPAND_VALUES( enums ) 				\
PP_SEQ_ENUM ( 							\
	PP_SEQ_FOR_EACH(ENUM_EXPAND_VALUES_MACRO, ~, enums))




#define ENUM_EXPAND_INITMAP_MACRO(r, data, elem) 		\
	stringmap.insert(make_pair((int_t)			\
		ENUM_CLASS::PP_SEQ_HEAD(elem),			\
		String{ boost::replace_all_copy( std::string{	\
		      PP_STRINGIZE(PP_SEQ_HEAD(elem))}, "_"," ")\
		}));


#define ENUM_EXPAND_INITMAP( enums ) 				\
	PP_SEQ_FOR_EACH(ENUM_EXPAND_INITMAP_MACRO, ~, enums)




#define ENUM_END 						\
}; 								\
typedef PP_CAT( H, ENUM_CLASS)::ENUM_CLASS ENUM_CLASS;



#define ENUM_BEGIN 						\
class PP_CAT( H, ENUM_CLASS)					\
{								\
	PP_CAT( H, ENUM_CLASS)() = delete;			\
	typedef ENUM_INT int_t;					\
enum class PP_CAT( T, ENUM_CLASS) : int_t {			\
	ENUM_EXPAND_ENUM(ENUM_VALUES)				\
};								\
public:								\
class ENUM_CLASS:						\
	public Enum<ENUM_CLASS,PP_CAT( T, ENUM_CLASS)>,		\
	ENUM_EXPAND_PROPERTIES(ENUM_PROPERTIES)			\
	public Void						\
{								\
public:								\
	typedef PP_CAT( H, ENUM_CLASS)::int_t int_t;		\
	static const PP_CAT( T, ENUM_CLASS)			\
		ENUM_EXPAND_VALUES(ENUM_VALUES) ;		\
	ENUM_CLASS( const PP_CAT( T, ENUM_CLASS) a):		\
		Enum<ENUM_CLASS,PP_CAT( T, ENUM_CLASS)>{a}{}	\
private:							\
	friend class Enum<ENUM_CLASS,PP_CAT( T, ENUM_CLASS)>;	\
	static bool Init_Map();					\
	static std::unordered_map< int_t, String> stringmap;	\
public:





#define ENUM_DEFINE									\
unordered_map< ENUM_CLASS::int_t, String> ENUM_CLASS::stringmap;			\
template<> const bool Enum<ENUM_CLASS,PP_CAT( H, ENUM_CLASS)::PP_CAT( T, ENUM_CLASS)>	\
	::init_map 	=  ENUM_CLASS::Init_Map();					\
template<> const String Enum<ENUM_CLASS,PP_CAT( H, ENUM_CLASS)::PP_CAT( T, ENUM_CLASS)>	\
	::adjective = 	String{ENUM_ADJECTIVE};						\
template<> const String Enum<ENUM_CLASS,PP_CAT( H, ENUM_CLASS)::PP_CAT( T, ENUM_CLASS)>	\
	::classname = 	String{PP_STRINGIZE(ENUM_CLASS)};				\
											\
bool ENUM_CLASS::Init_Map()								\
{											\
	ENUM_EXPAND_INITMAP(ENUM_VALUES)						\
	return true;									\
}


#endif // ENUM_HPP
