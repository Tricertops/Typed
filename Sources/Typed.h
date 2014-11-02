//
//  Typed.h
//  Typed
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TDeclarations.h"

#import "TMutableArray.h"
#import "TMutableSet.h"



TGenerate(NSString) // Used by TArrayGenerate itself.
TGenerate(NSSortDescriptor) // Used by TArrayGenerate itself.
TGenerate(NSDate)
TGenerate(NSNumber)
TGenerate(NSURL)


