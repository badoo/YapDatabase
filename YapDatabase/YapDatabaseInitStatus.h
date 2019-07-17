//
//  YapDatabaseInitStatus.h
//  YapDatabase
//
//  Created by Alexander Balaban on 16/07/2019.
//  Copyright © 2019 Badoo. All rights reserved.
//

#ifndef YapDatabaseInitStatus_h
#define YapDatabaseInitStatus_h

typedef enum : NSUInteger {
    YapDatabaseInitStatusSuccess,
    YapDatabaseInitStatusFailedDatabaseAlreadyExists,
    YapDatabaseInitStatusFailedCantOpenDatabaseConnection,
    YapDatabaseInitStatusFailedConfigurationFailed,
    YapDatabaseInitStatusFailedCreateTablesFailed,
    YapDatabaseInitStatusFailedCorruptRenameActionFailed,
    YapDatabaseInitStatusFailedCorruptDeleteActionFailed
} YapDatabaseInitStatus;

#endif /* YapDatabaseInitStatus_h */
