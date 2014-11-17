//
//  TCache.h
//  Typed
//
//  Created by Martin Kiss on 5.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TCollections.h"



_TArrayForward(NSString)



#define _TCacheCreateProtocol(Key,KPtr, Value,VPtr) \
/*! Types */ \
_TDictionaryForward(NSString, Value) \
/*! NSCache Interface */ \
_TCacheForward(Key, Value); \
@protocol TCache_##Key##_##Value <NSObject> \
- (TCache(Key, Value))self; \
- (TCache(Key, Value))init; \
- (BOOL)isEqual:(TCache(Key, Value))other; \
/*! Naming a Cache */ \
@property(copy) NSString *name; \
/*! Getting a Cached Value */ \
- (Value VPtr)objectForKey:(Key KPtr)key; \
/*! Adding and Removing Cached Values */ \
- (void)setObject:(Value VPtr)object forKey:(Key KPtr)key; \
- (void)setObject:(Value VPtr)object forKey:(Key KPtr)key cost:(NSUInteger)cost; \
- (void)removeObjectForKey:(Key KPtr)key; \
- (void)removeAllObjects; \
/*! Managing Cache Size */ \
@property NSUInteger countLimit; \
@property NSUInteger totalCostLimit; \
/*! Managing Discardable Content */ \
@property BOOL evictsObjectsWithDiscardedContent; \
/*! Delegate */ \
@property(assign) id<NSCacheDelegate> delegate; \
/*! Key-Value Coding */ \
- (Value VPtr)valueForKey:(NSString *)key; \
- (void)setValue:(Value VPtr)value forKey:(NSString *)key; \
- (id)valueForKeyPath:(NSString *)keyPath; \
- (void)setValue:(id)value forKeyPath:(NSString *)keyPath; \
- (TDictionary(NSString, Value))dictionaryWithValuesForKeys:(TArray(NSString))keys; \
- (void)setValuesForKeysWithDictionary:(TDictionary(NSString, Value))keyedValues; \
@end


