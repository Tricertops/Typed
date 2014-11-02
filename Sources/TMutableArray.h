//
//  TMutableArray.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TArray.h"



#define _TMutableArrayCreateProtocol(Element) \
@class Element; \
/*! NSMutableArray Interface */ \
@protocol TMutableArray_##Element <TArray_##Element> \
@end

