//
//  Typed+Foundation.h
//  Typed
//
//  Created by Martin Kiss on 21.2.15.
//  Copyright (c) 2015 Triceratops. All rights reserved.
//





#pragma mark - Collections


TGenerate(NSDate,*)
TGenerate(NSNumber,*)
TGenerate(NSObject,*)
TGenerate(NSSortDescriptor,*) // Used by sorting methods.
TGenerate(NSString,*) // Useds for KVC methods.
TGenerate(NSURL,*)





#pragma mark - Associative Collections


TAssociativeGenerate(NSNumber,*, NSNumber,*)
TAssociativeGenerate(NSNumber,*, NSObject,*)
TAssociativeGenerate(NSNumber,*, NSString,*)

TAssociativeGenerate(NSObject,*, NSObject,*)

TAssociativeGenerate(NSString,*, NSNumber,*)
TAssociativeGenerate(NSString,*, NSObject,*) // Useds for KVC methods.
TAssociativeGenerate(NSString,*, NSString,*)
TAssociativeGenerate(NSString,*, TArray(NSString),)


