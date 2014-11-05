//
//  TCache.h
//  Typed
//
//  Created by Martin Kiss on 5.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TAssociativeCollections.h"



#define _TCacheCreateProtocol(Key, Value) \
/*! Types */ \
@class Key, Value; \
/*! NSCache Interface */ \
@protocol TCache_##Key##_##Value <_TAssociativeProtocols> \
- (TCache(Key, Value))self; \
/*! Initializing a Cache */ \
- (TCache(Key, Value))init; \
/*! Naming a Cache */ \
@property(copy) NSString *name; \
/*! Getting a Cached Value */ \
- (Value *)objectForKey:(Key *)key; \
/*! Adding and Removing Cached Values */ \
- (void)setObject:(Value *)object forKey:(Key *)key; \
- (void)setObject:(Value *)object forKey:(Key *)key cost:(NSUInteger)cost; \
- (void)removeObjectForKey:(Key *)key; \
- (void)removeAllObjects; \
/*! Managing Cache Size */ \
@property NSUInteger countLimit; \
@property NSUInteger totalCostLimit; \
/*! Managing Discardable Content */ \
@property BOOL evictsObjectsWithDiscardedContent; \
/*! Delegate */ \
@property(assign) id<NSCacheDelegate> delegate; \
@end


