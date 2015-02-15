//
//  TWeakDictionary.h
//  Typed
//
//  Created by Martin Kiss on 15.2.15.
//  Copyright (c) 2015 Triceratops. All rights reserved.
//

#import "TCollections.h"





#define _TWeakDictionaryCreateProtocol(Key, KPtr, Value, VPtr) \
/*! Types */ \
_TDictionaryForward(Key, Value); \
/*! NSMapTable Interface */ \
_TWeakDictionaryForward(Key, Value); \
@protocol TWeakDictionary_##Key##_##Value <_TWeakProtocols> \
- (TWeakDictionary(Key, Value))self; \
- (NSMapTable *)untyped; \
- (TDictionary(Key, Value))strong; \
- (Key KPtr)T_Key; \
- (Value VPtr)T_Value; \
- (Key KPtr)T_Enumeration; \
/*! Querying a Dictionary */ \
@property(readonly) NSUInteger count; \
- (Value VPtr)objectForKey:(Key KPtr)key; \
- (Value VPtr)objectForKeyedSubscript:(Key KPtr)key; \
- (NSEnumerator *)keyEnumerator; \
- (NSEnumerator *)objectEnumerator; \
/*! Mutating a Dictionary */ \
- (void)setObject:(Value VPtr)anObject forKey:(Key KPtr)key; \
- (void)setObject:(Value VPtr)object forKeyedSubscript:(Key KPtr)key; \
- (void)removeObjectForKey:(Key KPtr)key; \
- (void)removeAllObjects; \
/*! Comparing Dictionaries */ \
- (BOOL)isEqual:(TWeakDictionary(Key, Value))other; \
/*! Copying a Dictionary */ \
- (TWeakDictionary(Key, Value))copy; \
- (TWeakDictionary(Key, Value))copyWithZone:(NSZone *)zone; \
/*! Creating a Description */ \
@property(readonly, copy) NSString *description; \
@end



@interface NSMapTable (TWeakDictionary)

+ (instancetype)weakToWeak;
+ (instancetype)weakToStrong;
+ (instancetype)strongToWeak;

@end


