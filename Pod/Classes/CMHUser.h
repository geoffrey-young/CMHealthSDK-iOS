#import <Foundation/Foundation.h>
#import <ResearchKit/ResearchKit.h>

@class CMHUserData;

typedef void(^CMHUserAuthCompletion)(NSError * _Nullable error);
typedef void(^CMHUserLogoutCompletion)(NSError * _Nullable error);

@interface CMHUser : NSObject

+ (_Nonnull instancetype)currentUser;

- (void)signUpWithEmail:(NSString *_Nonnull)email
               password:(NSString *_Nonnull)password
             andConsent:(ORKTaskResult *_Nonnull)consentResult
         withCompletion:(_Nullable CMHUserAuthCompletion)block;

- (void)loginWithEmail:(NSString *_Nonnull)email
              password:(NSString *_Nonnull)password
         andCompletion:(_Nullable CMHUserAuthCompletion)block;

- (void)logoutWithCompletion:(_Nullable CMHUserLogoutCompletion)block;

@property (nonatomic, nullable, readonly) CMHUserData *userData;
@property (nonatomic, readonly) BOOL isLoggedIn;

@end