//
//  TCMacros.h
//  TC
//
//  Created by Damien TERRIER on 09/08/13.
//  Copyright (c) 2013 TagCommander. All rights reserved.
//

#ifndef TC_TCMacros_h
#define TC_TCMacros_h

#define TC_EXEC_UNDEFINED -1
#define TC_EXEC_START 0
#define TC_EXEC_EXECUTE 1
#define TC_EXEC_STOP 2

#ifdef SYNTHESIZE_CONSTS
# define STR_CONST(name, value) NSString* const name = @ value
#else
# define STR_CONST(name, value) extern NSString* const name
#endif


/**
 * @brief Singleton GCD Macro
 */
// source: http://lukeredpath.co.uk/blog/2011/07/01/a-note-on-objective-c-singletons/
#define SINGLETON_CLASS_GCD(classname)                        \
\
+ (classname *)sharedInstance {                      \
\
static dispatch_once_t pred;                        \
__strong static classname * sharedInstance = nil;\
dispatch_once( &pred, ^{                            \
sharedInstance = [[self alloc] init]; });    \
return sharedInstance;                           \
}


#define SINGLETON_CLASS(classname) \
\
+ (classname *)c \
{ \
static classname *sharedInstance = nil; \
if (sharedInstance == nil) \
{ \
sharedInstance = [[self alloc] init]; \
} \
return sharedInstance; \
}

#define SINGLETON_CLASS_H(classname) \
\
+ (classname*) sharedInstance;


#define NOTIFICATION_H(attributName) \
\
+ (NSString*) attributName;


#define NOTIFICATION_M(attributName, strValue) \
\
static NSString* attributName = strValue; \
+ (NSString*) attributName { return attributName; }


#define STATIC_CONST_H(attributType, attributName) \
\
+ (const attributType) attributName;


#define STATIC_CONST_M(attributType, attributName, iValue) \
\
static const attributType attributName = iValue; \
+ (const attributType) attributName { return attributName; }


#define STATIC_ATTRIBUT_H(attributType, attributName) \
\
+ (attributType) attributName;


#define STATIC_ATTRIBUT_M(attributType, attributName, theValue) \
\
static attributType attributName = theValue; \
+ (attributType) attributName { return attributName; }


#endif
