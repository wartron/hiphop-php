/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#ifndef __ICU__TRANSLITERATOR_H__
#define __ICU__TRANSLITERATOR_H__

#include <boost/scoped_ptr.hpp>
#include <unicode/translit.h>

// Avoid dragging in the icu namespace.
#ifndef U_USING_ICU_NAMESPACE
#define U_USING_ICU_NAMESPACE 0
#endif

namespace HPHP {
// Wrapper class around icu::Transliterator that provides a default constructor
// so that it can be used in thread-local storage.
// The easiest  way to use this as a thread-local variable is to make a small
// subclass with a fixed format string.
class ICUTransliterator {
 public:
  ICUTransliterator() : uStatus_(U_ZERO_ERROR) {}
  bool set(const icu::UnicodeString& transformId);
  void transliterate(icu::UnicodeString& s);
 private:
  boost::scoped_ptr<icu::Transliterator> translitPtr_;
  UErrorCode uStatus_;
};

}

#endif // __ICU__TRANSLITERATOR_H__
