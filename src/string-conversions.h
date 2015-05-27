#pragma once

#include <vector>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <cctype>
#include <iomanip>
#include <algorithm>
#include <math.h>

#include "glm/glm.hpp"

//---------------------------------------- Conversions

/*  Transform the string into lower letters */
inline void toLower( std::string &_str ){
    for (int i = 0; _str[i]; i++) {
        _str[i] = tolower(_str[i]);
    }
}

/*  Return new string with all into lower letters */
inline std::string getLower(const std::string& _str ){
    std::string std = _str;
    toLower(std);
    return std;
}

/*  Extract extrange characters from a string */
inline void purifyString( std::string& _s ){
    for ( std::string::iterator it = _s.begin(), itEnd = _s.end(); it!=itEnd; ++it){
        if ( static_cast<unsigned int>(*it) < 32 || static_cast<unsigned int>(*it) > 127 ){
            (*it) = ' ';
        }
    }
}

inline int getInt(const std::string &_intString) {
    int x = 0;
    std::istringstream cur(_intString);
    cur >> x;
    return x;
}

inline float getFloat(const std::string &_floatString) {
    float x = 0;
    std::istringstream cur(_floatString);
    cur >> x;
    return x;
}

inline double getDouble(const std::string &_doubleString) {
    double x = 0;
    std::istringstream cur(_doubleString);
    cur >> x;
    return x;
}

inline bool getBool(const std::string &_boolString) {
    static const std::string trueString = "true";
    static const std::string falseString = "false";
    
    std::string lower = getLower(_boolString);
    
    if(lower == trueString) {
        return true;
    }
    if(lower == falseString) {
        return false;
    }
    
    bool x = false;
    std::istringstream cur(lower);
    cur >> x;
    return x;
}

inline char getChar(const std::string &_charString) {
    char x = '\0';
    std::istringstream cur(_charString);
    cur >> x;
    return x;
}

inline std::string getString(bool _bool){
    std::ostringstream strStream;
    strStream << (_bool?"true":"false") ;
    return strStream.str();
}

// Translations

template <class T>
std::string getString(const T& _value){
    std::ostringstream out;
    out << _value;
    return out.str();
}

/// like sprintf "%4f" format, in this example precision=4
template <class T>
std::string getString(const T& _value, int _precision){
    std::ostringstream out;
    out << std::fixed << std::setprecision(_precision) << _value;
    return out.str();
}

/// like sprintf "% 4d" or "% 4f" format, in this example width=4, fill=' '
template <class T>
std::string getString(const T& _value, int _width, char _fill ){
    std::ostringstream out;
    out << std::fixed << std::setfill(_fill) << std::setw(_width) << _value;
    return out.str();
}

/// like sprintf "%04.2d" or "%04.2f" format, in this example precision=2, width=4, fill='0'
template <class T>
std::string getString(const T& _value, int _precision, int _width, char _fill ){
    std::ostringstream out;
    out << std::fixed << std::setfill(_fill) << std::setw(_width) << std::setprecision(_precision) << _value;
    return out.str();
}

//---------------------------------------- Conversions

inline int toInt(const std::string &_intString) {
    int x = 0;
    std::istringstream cur(_intString);
    cur >> x;
    return x;
}

inline float toFloat(const std::string &_floatString) {
    float x = 0;
    std::istringstream cur(_floatString);
    cur >> x;
    return x;
}

inline double toDouble(const std::string &_doubleString) {
    double x = 0;
    std::istringstream cur(_doubleString);
    cur >> x;
    return x;
}

inline bool toBool(const std::string &_boolString) {
    static const std::string trueString = "true";
    static const std::string falseString = "false";
    
    std::string lower = getLower(_boolString);
    
    if(lower == trueString) {
        return true;
    }
    if(lower == falseString) {
        return false;
    }
    
    bool x = false;
    std::istringstream cur(lower);
    cur >> x;
    return x;
}

inline char ofToChar(const std::string &_charString) {
    char x = '\0';
    std::istringstream cur(_charString);
    cur >> x;
    return x;
}

inline std::string toString(bool _bool){
    std::ostringstream strStream;
    strStream << (_bool?"true":"false") ;
    return strStream.str();
}

template <class T>
std::string toString(const T& _value){
    std::ostringstream out;
    out << _value;
    return out.str();
}

/// like sprintf "%4f" format, in this example precision=4
template <class T>
std::string toString(const T& _value, int _precision){
    std::ostringstream out;
    out << std::fixed << std::setprecision(_precision) << _value;
    return out.str();
}

/// like sprintf "% 4d" or "% 4f" format, in this example width=4, fill=' '
template <class T>
std::string toString(const T& _value, int _width, char _fill ){
    std::ostringstream out;
    out << std::fixed << std::setfill(_fill) << std::setw(_width) << _value;
    return out.str();
}

/// like sprintf "%04.2d" or "%04.2f" format, in this example precision=2, width=4, fill='0'
template <class T>
std::string toString(const T& _value, int _precision, int _width, char _fill ){
    std::ostringstream out;
    out << std::fixed << std::setfill(_fill) << std::setw(_width) << std::setprecision(_precision) << _value;
    return out.str();
}

inline std::string toString(const glm::vec2 &_vec, char _sep = ','){
    std::ostringstream strStream;
    strStream<< _vec.x << _sep << _vec.y << _sep;
    return strStream.str();
}

inline std::string toString(const glm::vec3 &_vec, char _sep = ','){
    std::ostringstream strStream;
    strStream<< _vec.x << _sep << _vec.y << _sep << _vec.z;
    return strStream.str();
}

inline std::string toString(const glm::vec4 &_vec, char _sep = ','){
    std::ostringstream strStream;
    strStream<< _vec.x << _sep << _vec.y << _sep << _vec.z << _sep << _vec.w;
    return strStream.str();
}

//-------------------------------------------------- << and >>

inline std::ostream& operator<<(std::ostream& os, const glm::vec3& vec) {
    os << vec.x << ", " << vec.y << ", " << vec.z;
    return os;
}

inline std::istream& operator>>(std::istream& is, glm::vec3& vec) {
    is >> vec.x;
    is.ignore(2);
    is >> vec.y;
    is.ignore(2);
    is >> vec.z;
    return is;
}
