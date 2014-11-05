//
//  TMutableDictionary.h
//  Typed
//
//  Created by Martin Kiss on 5.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TDictionary.h"


#define _TMutableDictionaryCreateProtocol(Key, Value) \
/*! Types */ \
@class Key, Value; \
_TArrayForward(Key) \
/*! NSMutableDictionary Interface */ \
@protocol TMutableDictionary_##Key##_##Value <_TAssociativeProtocols> \
- (TMutableDictionary(Key, Value))self; \
/*! Initializing a Dictionary */ \
- (TMutableDictionary(Key, Value))initWithDictionary:(TDictionary(Key, Value))other; \
- (TMutableDictionary(Key, Value))initWithDictionary:(TDictionary(Key, Value))other copyItems:(BOOL)flag; \
- (TMutableDictionary(Key, Value))initWithObjects:(TArray(Value))objects forKeys:(TArray(Key))keys; \
- (TMutableDictionary(Key, Value))initWithObjects:(const Value * __autoreleasing [])objects forKeys:(const Key<NSCopying> * __autoreleasing [])keys count:(NSUInteger)count; \
- (TMutableDictionary(Key, Value))initWithObjectsAndKeys:(Value *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TMutableDictionary(Key, Value))initWithContentsOfFile:(NSString *)path; \
- (TMutableDictionary(Key, Value))initWithContentsOfURL:(NSURL *)url; \
- (TMutableDictionary(Key, Value))init; \
- (TMutableDictionary(Key, Value))initWithCoder:(NSCoder *)decoder; \
- (TMutableDictionary(Key, Value))initWithCapacity:(NSUInteger)capacity; \
/*! Adding & Replacing Entries */ \
- (void)setObject:(Value *)anObject forKey:(Key<NSCopying> *)key; \
- (void)setObject:(Value *)object forKeyedSubscript:(Key<NSCopying> *)key; \
- (void)setValue:(Value *)value forKey:(NSString *)key; \
- (void)addEntriesFromDictionary:(TDictionary(Key, Value))other; \
- (void)setDictionary:(TDictionary(Key, Value))other; \
/*! Removing Entries */ \
- (void)removeObjectForKey:(Key *)key; \
- (void)removeObjectsForKeys:(TArray(Key))keys; \
- (void)removeAllObjects; \
@end


