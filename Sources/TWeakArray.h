//
//  TWeakArray.h
//  Typed
//
//  Created by Martin Kiss on 15.2.15.
//  Copyright (c) 2015 Triceratops. All rights reserved.
//

#import "TCollections.h"





#define _TWeakArrayCreateProtocol(Element, Ptr) \
/*! Types */ \
_TArrayForward(Element) \
/*! NSPointerArray Interface */ \
_TWeakArrayForward(Element) \
@protocol TWeakArray_##Element <_TWeakProtocols> \
- (TWeakArray(Element))self; \
- (NSPointerArray *)untyped; \
- (TArray(Element))strong; \
- (Element Ptr)T_Element; \
- (Element Ptr)T_Enumeration; \
/*! Querying an Array */ \
@property (readonly) NSUInteger count; \
- (Element Ptr )objectAtIndex:(NSUInteger)index; \
- (Element Ptr )objectAtIndexedSubscript:(NSUInteger)index; \
/*! Adding Objects */ \
- (void)addObject:(Element Ptr )object; \
- (void)insertObject:(Element Ptr )object atIndex:(NSUInteger)index; \
/*! Removing Objects */ \
- (void)removeObjectAtIndex:(NSUInteger)index; \
- (void)compact; \
/*! Replacing Objects */ \
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(Element Ptr )object; \
- (void)setObject:(Element Ptr )object atIndexedSubscript:(NSUInteger)index; \
/*! Comparing Arrays */ \
- (BOOL)isEqual:(TWeakArray(Element))other; \
/*! Copying an Array */ \
- (TWeakArray(Element))copy; \
- (TWeakArray(Element))copyWithZone:(NSZone *)zone; \
/*! Creating a Description */ \
@property (readonly, copy) NSString *description; \
/*! Extension: Random */ \
@property (readonly) Element Ptr randomObject; \
@property (readonly) NSUInteger randomIndex; \
@end \


