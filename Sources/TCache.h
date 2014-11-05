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
@end



