//
//  TCountedSet.h
//  Typed
//
//  Created by Martin Kiss on 4.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TMutableSet.h"



#define _TCountedSetCreateProtocol(Element) \
@class Element; \
/*! NSMutableSet Interface */ \
@protocol TCountedSet_##Element <TMutableSet_##Element> \
@end


