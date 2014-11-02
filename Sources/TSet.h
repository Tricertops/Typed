//
//  TSet.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TDeclarations.h"



#define _TSetCreateProtocol(Element) \
/*! Types */ \
@class Element; \
_TArrayForward(Element) \
/*! NSArray Interface */ \
@protocol TSet_##Element <_TProtocols> \
@end


