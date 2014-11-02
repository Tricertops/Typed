//
//  TOrderedSet.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TDeclarations.h"



#define _TOrderedSetCreateProtocol(Element) \
/*! Types */ \
@class Element; \
_TArrayForward(Element) \
_TSetForward(Element) \
/*! NSOrderedSet Interface */ \
@protocol TOrderedSet_##Element <_TProtocols> \
@end


