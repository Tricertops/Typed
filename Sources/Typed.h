//
//  Typed.h
//  Typed
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TCollections.h"

#import "TMutableArray.h"
#import "TWeakArray.h"
#import "TMutableSet.h"
#import "TCountedSet.h"
#import "TWeakSet.h"
#import "TMutableOrderedSet.h"
#import "TMutableDictionary.h"
#import "TCache.h"
#import "TWeakDictionary.h"


//TODO: Extensibility, since categories doesn’t work.
//TODO: Create prepopulated with copies of single object (Array).
//TODO: Map to collection of different type (Array, Set, OrderedSet)
//TODO: Subcollection from/to index (Array, OrderedSet)
//TODO: Add object if non-nil (Array, Set, OrderedSet, Dictionary).

//TODO: Flattened array?
//TODO: Create mapped dictionary?


#pragma mark -

TGenerate(id,)
TGenerate(Class,)
TAssociativeGenerate(id,, id,)

#import "Typed+Foundation.h"
#if TARGET_OS_IPHONE
    #import "Typed+UIKit.h"
#endif
