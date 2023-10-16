
asm(".global sceAppMessagingClearEventFlag\n"
    ".type   sceAppMessagingClearEventFlag, @function\n"
    ".symver sceAppMessagingClearEventFlag, sceAppMessagingClearEventFlag@@0x6A565F45DAF644FF\n"
    "sceAppMessagingClearEventFlag:\n");

asm(".global sceAppMessagingReceiveMsg\n"
    ".type   sceAppMessagingReceiveMsg, @function\n"
    ".symver sceAppMessagingReceiveMsg, sceAppMessagingReceiveMsg@@0x8CA800525E9C2F2D\n"
    "sceAppMessagingReceiveMsg:\n");

asm(".global sceAppMessagingSendMsg\n"
    ".type   sceAppMessagingSendMsg, @function\n"
    ".symver sceAppMessagingSendMsg, sceAppMessagingSendMsg@@0xFB3BAFDB416C5EB0\n"
    "sceAppMessagingSendMsg:\n");

asm(".global sceAppMessagingSendMsgToShellCore\n"
    ".type   sceAppMessagingSendMsgToShellCore, @function\n"
    ".symver sceAppMessagingSendMsgToShellCore, sceAppMessagingSendMsgToShellCore@@0x1C8C04BF1E247FAA\n"
    "sceAppMessagingSendMsgToShellCore:\n");

asm(".global sceAppMessagingSendMsgToShellUI\n"
    ".type   sceAppMessagingSendMsgToShellUI, @function\n"
    ".symver sceAppMessagingSendMsgToShellUI, sceAppMessagingSendMsgToShellUI@@0xE72832D483D48797\n"
    "sceAppMessagingSendMsgToShellUI:\n");

asm(".global sceAppMessagingSetEventFlag\n"
    ".type   sceAppMessagingSetEventFlag, @function\n"
    ".symver sceAppMessagingSetEventFlag, sceAppMessagingSetEventFlag@@0x85DA0C6CC1480DD1\n"
    "sceAppMessagingSetEventFlag:\n");

asm(".global sceAppMessagingTryGetEventFlag\n"
    ".type   sceAppMessagingTryGetEventFlag, @function\n"
    ".symver sceAppMessagingTryGetEventFlag, sceAppMessagingTryGetEventFlag@@0x88A3572AC52D3A36\n"
    "sceAppMessagingTryGetEventFlag:\n");

asm(".global sceAppMessagingTryReceiveMsg\n"
    ".type   sceAppMessagingTryReceiveMsg, @function\n"
    ".symver sceAppMessagingTryReceiveMsg, sceAppMessagingTryReceiveMsg@@0x6554575EA8F59FCD\n"
    "sceAppMessagingTryReceiveMsg:\n");

asm(".global sceLncUtilAcquireCpuBudgetOfExtraAudioDevices\n"
    ".type   sceLncUtilAcquireCpuBudgetOfExtraAudioDevices, @function\n"
    ".symver sceLncUtilAcquireCpuBudgetOfExtraAudioDevices, sceLncUtilAcquireCpuBudgetOfExtraAudioDevices@@0x577E741F4877E485\n"
    "sceLncUtilAcquireCpuBudgetOfExtraAudioDevices:\n");

asm(".global sceLncUtilAcquireCpuBudgetOfImeForBigApp\n"
    ".type   sceLncUtilAcquireCpuBudgetOfImeForBigApp, @function\n"
    ".symver sceLncUtilAcquireCpuBudgetOfImeForBigApp, sceLncUtilAcquireCpuBudgetOfImeForBigApp@@0x1A628C1F0BF12E5A\n"
    "sceLncUtilAcquireCpuBudgetOfImeForBigApp:\n");

asm(".global sceLncUtilAcquireCpuBudgetOfInGameStore\n"
    ".type   sceLncUtilAcquireCpuBudgetOfInGameStore, @function\n"
    ".symver sceLncUtilAcquireCpuBudgetOfInGameStore, sceLncUtilAcquireCpuBudgetOfInGameStore@@0x982DC12891656CD2\n"
    "sceLncUtilAcquireCpuBudgetOfInGameStore:\n");

asm(".global sceLncUtilActivateCdlg\n"
    ".type   sceLncUtilActivateCdlg, @function\n"
    ".symver sceLncUtilActivateCdlg, sceLncUtilActivateCdlg@@0xE1D59F34A393D6C8\n"
    "sceLncUtilActivateCdlg:\n");

asm(".global sceLncUtilAddLocalProcess\n"
    ".type   sceLncUtilAddLocalProcess, @function\n"
    ".symver sceLncUtilAddLocalProcess, sceLncUtilAddLocalProcess@@0x8FBDA5B2DEC116E7\n"
    "sceLncUtilAddLocalProcess:\n");

asm(".global sceLncUtilBlockAppSuspend\n"
    ".type   sceLncUtilBlockAppSuspend, @function\n"
    ".symver sceLncUtilBlockAppSuspend, sceLncUtilBlockAppSuspend@@0xBB52550CFDBCC9C8\n"
    "sceLncUtilBlockAppSuspend:\n");

asm(".global sceLncUtilBlockingGetEventForDaemon\n"
    ".type   sceLncUtilBlockingGetEventForDaemon, @function\n"
    ".symver sceLncUtilBlockingGetEventForDaemon, sceLncUtilBlockingGetEventForDaemon@@0x003315D9A68A8636\n"
    "sceLncUtilBlockingGetEventForDaemon:\n");

asm(".global sceLncUtilContinueApp\n"
    ".type   sceLncUtilContinueApp, @function\n"
    ".symver sceLncUtilContinueApp, sceLncUtilContinueApp@@0xF77327CE19000209\n"
    "sceLncUtilContinueApp:\n");

asm(".global sceLncUtilCrashSyscore\n"
    ".type   sceLncUtilCrashSyscore, @function\n"
    ".symver sceLncUtilCrashSyscore, sceLncUtilCrashSyscore@@0xB9AA99BE06B71648\n"
    "sceLncUtilCrashSyscore:\n");

asm(".global sceLncUtilDeactivateCdlg\n"
    ".type   sceLncUtilDeactivateCdlg, @function\n"
    ".symver sceLncUtilDeactivateCdlg, sceLncUtilDeactivateCdlg@@0xE28A1F150B9D7F1D\n"
    "sceLncUtilDeactivateCdlg:\n");

asm(".global sceLncUtilDeclareReadyForSuspend\n"
    ".type   sceLncUtilDeclareReadyForSuspend, @function\n"
    ".symver sceLncUtilDeclareReadyForSuspend, sceLncUtilDeclareReadyForSuspend@@0x18752A46B081DA13\n"
    "sceLncUtilDeclareReadyForSuspend:\n");

asm(".global sceLncUtilDisableSuspendNotification\n"
    ".type   sceLncUtilDisableSuspendNotification, @function\n"
    ".symver sceLncUtilDisableSuspendNotification, sceLncUtilDisableSuspendNotification@@0x1A470D641A220DCB\n"
    "sceLncUtilDisableSuspendNotification:\n");

asm(".global sceLncUtilEnableSuspendNotification\n"
    ".type   sceLncUtilEnableSuspendNotification, @function\n"
    ".symver sceLncUtilEnableSuspendNotification, sceLncUtilEnableSuspendNotification@@0x0069ECCB5CD5DF8A\n"
    "sceLncUtilEnableSuspendNotification:\n");

asm(".global sceLncUtilFinishSpecialResume\n"
    ".type   sceLncUtilFinishSpecialResume, @function\n"
    ".symver sceLncUtilFinishSpecialResume, sceLncUtilFinishSpecialResume@@0x52E90BD045CB425B\n"
    "sceLncUtilFinishSpecialResume:\n");

asm(".global sceLncUtilForceKillApp\n"
    ".type   sceLncUtilForceKillApp, @function\n"
    ".symver sceLncUtilForceKillApp, sceLncUtilForceKillApp@@0xBEAB98AEF2268CF8\n"
    "sceLncUtilForceKillApp:\n");

asm(".global sceLncUtilForceKillLocalProcess\n"
    ".type   sceLncUtilForceKillLocalProcess, @function\n"
    ".symver sceLncUtilForceKillLocalProcess, sceLncUtilForceKillLocalProcess@@0x003525D600DF6EA1\n"
    "sceLncUtilForceKillLocalProcess:\n");

asm(".global sceLncUtilGetAppCategory\n"
    ".type   sceLncUtilGetAppCategory, @function\n"
    ".symver sceLncUtilGetAppCategory, sceLncUtilGetAppCategory@@0xBDB30441CCFA3BC8\n"
    "sceLncUtilGetAppCategory:\n");

asm(".global sceLncUtilGetAppCategoryType\n"
    ".type   sceLncUtilGetAppCategoryType, @function\n"
    ".symver sceLncUtilGetAppCategoryType, sceLncUtilGetAppCategoryType@@0x2ED18C7F2D290A3E\n"
    "sceLncUtilGetAppCategoryType:\n");

asm(".global sceLncUtilGetAppFocusedAppStatus\n"
    ".type   sceLncUtilGetAppFocusedAppStatus, @function\n"
    ".symver sceLncUtilGetAppFocusedAppStatus, sceLncUtilGetAppFocusedAppStatus@@0x8BED6496E0C84E54\n"
    "sceLncUtilGetAppFocusedAppStatus:\n");

asm(".global sceLncUtilGetAppId\n"
    ".type   sceLncUtilGetAppId, @function\n"
    ".symver sceLncUtilGetAppId, sceLncUtilGetAppId@@0x31517E7A57B1F12C\n"
    "sceLncUtilGetAppId:\n");

asm(".global sceLncUtilGetAppIdListOfBigApp\n"
    ".type   sceLncUtilGetAppIdListOfBigApp, @function\n"
    ".symver sceLncUtilGetAppIdListOfBigApp, sceLncUtilGetAppIdListOfBigApp@@0x007733822EF85532\n"
    "sceLncUtilGetAppIdListOfBigApp:\n");

asm(".global sceLncUtilGetAppIdOfRunningBigApp\n"
    ".type   sceLncUtilGetAppIdOfRunningBigApp, @function\n"
    ".symver sceLncUtilGetAppIdOfRunningBigApp, sceLncUtilGetAppIdOfRunningBigApp@@0x4A84142C80DDF55E\n"
    "sceLncUtilGetAppIdOfRunningBigApp:\n");

asm(".global sceLncUtilGetAppLaunchedUser\n"
    ".type   sceLncUtilGetAppLaunchedUser, @function\n"
    ".symver sceLncUtilGetAppLaunchedUser, sceLncUtilGetAppLaunchedUser@@0xA18402F50BA3E8DA\n"
    "sceLncUtilGetAppLaunchedUser:\n");

asm(".global sceLncUtilGetAppStatus\n"
    ".type   sceLncUtilGetAppStatus, @function\n"
    ".symver sceLncUtilGetAppStatus, sceLncUtilGetAppStatus@@0x0F14648BB4F6138E\n"
    "sceLncUtilGetAppStatus:\n");

asm(".global sceLncUtilGetAppStatusList\n"
    ".type   sceLncUtilGetAppStatusList, @function\n"
    ".symver sceLncUtilGetAppStatusList, sceLncUtilGetAppStatusList@@0xA4C2B6453D1CCAEB\n"
    "sceLncUtilGetAppStatusList:\n");

asm(".global sceLncUtilGetAppStatusListForShellUIReboot\n"
    ".type   sceLncUtilGetAppStatusListForShellUIReboot, @function\n"
    ".symver sceLncUtilGetAppStatusListForShellUIReboot, sceLncUtilGetAppStatusListForShellUIReboot@@0x7323B94A12717671\n"
    "sceLncUtilGetAppStatusListForShellUIReboot:\n");

asm(".global sceLncUtilGetAppTitleId\n"
    ".type   sceLncUtilGetAppTitleId, @function\n"
    ".symver sceLncUtilGetAppTitleId, sceLncUtilGetAppTitleId@@0x834C131BD2889B32\n"
    "sceLncUtilGetAppTitleId:\n");

asm(".global sceLncUtilGetAppType\n"
    ".type   sceLncUtilGetAppType, @function\n"
    ".symver sceLncUtilGetAppType, sceLncUtilGetAppType@@0xD4041FEE8F20A477\n"
    "sceLncUtilGetAppType:\n");

asm(".global sceLncUtilGetCdlgExec\n"
    ".type   sceLncUtilGetCdlgExec, @function\n"
    ".symver sceLncUtilGetCdlgExec, sceLncUtilGetCdlgExec@@0xEF25E358B5891475\n"
    "sceLncUtilGetCdlgExec:\n");

asm(".global sceLncUtilGetCdlgType\n"
    ".type   sceLncUtilGetCdlgType, @function\n"
    ".symver sceLncUtilGetCdlgType, sceLncUtilGetCdlgType@@0x5E319E9BAFA49FB5\n"
    "sceLncUtilGetCdlgType:\n");

asm(".global sceLncUtilGetCoredumpState\n"
    ".type   sceLncUtilGetCoredumpState, @function\n"
    ".symver sceLncUtilGetCoredumpState, sceLncUtilGetCoredumpState@@0x0A055D97D4A9D46D\n"
    "sceLncUtilGetCoredumpState:\n");

asm(".global sceLncUtilGetDbgExecutablePath\n"
    ".type   sceLncUtilGetDbgExecutablePath, @function\n"
    ".symver sceLncUtilGetDbgExecutablePath, sceLncUtilGetDbgExecutablePath@@0x75E09873B89A0B94\n"
    "sceLncUtilGetDbgExecutablePath:\n");

asm(".global sceLncUtilGetEventForDaemon\n"
    ".type   sceLncUtilGetEventForDaemon, @function\n"
    ".symver sceLncUtilGetEventForDaemon, sceLncUtilGetEventForDaemon@@0xC948740483DB855A\n"
    "sceLncUtilGetEventForDaemon:\n");

asm(".global sceLncUtilGetEventForShellUI\n"
    ".type   sceLncUtilGetEventForShellUI, @function\n"
    ".symver sceLncUtilGetEventForShellUI, sceLncUtilGetEventForShellUI@@0x66E7283A636C6FBC\n"
    "sceLncUtilGetEventForShellUI:\n");

asm(".global sceLncUtilGetGpuCrashFullDumpAppStatus\n"
    ".type   sceLncUtilGetGpuCrashFullDumpAppStatus, @function\n"
    ".symver sceLncUtilGetGpuCrashFullDumpAppStatus, sceLncUtilGetGpuCrashFullDumpAppStatus@@0xA239AF34A419354C\n"
    "sceLncUtilGetGpuCrashFullDumpAppStatus:\n");

asm(".global sceLncUtilGetLocalProcessStatusList\n"
    ".type   sceLncUtilGetLocalProcessStatusList, @function\n"
    ".symver sceLncUtilGetLocalProcessStatusList, sceLncUtilGetLocalProcessStatusList@@0xC06A1B492AC1338B\n"
    "sceLncUtilGetLocalProcessStatusList:\n");

asm(".global sceLncUtilGetParentSocket\n"
    ".type   sceLncUtilGetParentSocket, @function\n"
    ".symver sceLncUtilGetParentSocket, sceLncUtilGetParentSocket@@0x1D15E35288E51BBD\n"
    "sceLncUtilGetParentSocket:\n");

asm(".global sceLncUtilGetResultKillApp\n"
    ".type   sceLncUtilGetResultKillApp, @function\n"
    ".symver sceLncUtilGetResultKillApp, sceLncUtilGetResultKillApp@@0x90E77BE6A0E5C413\n"
    "sceLncUtilGetResultKillApp:\n");

asm(".global sceLncUtilGetResultLaunchAppByTitleId\n"
    ".type   sceLncUtilGetResultLaunchAppByTitleId, @function\n"
    ".symver sceLncUtilGetResultLaunchAppByTitleId, sceLncUtilGetResultLaunchAppByTitleId@@0x2D9B3A85F3CC9ECA\n"
    "sceLncUtilGetResultLaunchAppByTitleId:\n");

asm(".global sceLncUtilGetVideoFinalizeState\n"
    ".type   sceLncUtilGetVideoFinalizeState, @function\n"
    ".symver sceLncUtilGetVideoFinalizeState, sceLncUtilGetVideoFinalizeState@@0x0000000000000000\n"
    "sceLncUtilGetVideoFinalizeState:\n");

asm(".global sceLncUtilInitialize\n"
    ".type   sceLncUtilInitialize, @function\n"
    ".symver sceLncUtilInitialize, sceLncUtilInitialize@@0x007D0F0D777DC505\n"
    "sceLncUtilInitialize:\n");

asm(".global sceLncUtilIsActiveCdlg\n"
    ".type   sceLncUtilIsActiveCdlg, @function\n"
    ".symver sceLncUtilIsActiveCdlg, sceLncUtilIsActiveCdlg@@0x3F2347EE9E0B570F\n"
    "sceLncUtilIsActiveCdlg:\n");

asm(".global sceLncUtilIsAppLaunched\n"
    ".type   sceLncUtilIsAppLaunched, @function\n"
    ".symver sceLncUtilIsAppLaunched, sceLncUtilIsAppLaunched@@0x206AC9B0F34BEA7E\n"
    "sceLncUtilIsAppLaunched:\n");

asm(".global sceLncUtilIsAppSuspended\n"
    ".type   sceLncUtilIsAppSuspended, @function\n"
    ".symver sceLncUtilIsAppSuspended, sceLncUtilIsAppSuspended@@0xB5E1A83D69C481DE\n"
    "sceLncUtilIsAppSuspended:\n");

asm(".global sceLncUtilIsCdlgActivated\n"
    ".type   sceLncUtilIsCdlgActivated, @function\n"
    ".symver sceLncUtilIsCdlgActivated, sceLncUtilIsCdlgActivated@@0x00DF892F772781DE\n"
    "sceLncUtilIsCdlgActivated:\n");

asm(".global sceLncUtilIsCpuBudgetOfExtraAudioDevicesAvailable\n"
    ".type   sceLncUtilIsCpuBudgetOfExtraAudioDevicesAvailable, @function\n"
    ".symver sceLncUtilIsCpuBudgetOfExtraAudioDevicesAvailable, sceLncUtilIsCpuBudgetOfExtraAudioDevicesAvailable@@0x894B0E3475420DB4\n"
    "sceLncUtilIsCpuBudgetOfExtraAudioDevicesAvailable:\n");

asm(".global sceLncUtilIsHostBoot\n"
    ".type   sceLncUtilIsHostBoot, @function\n"
    ".symver sceLncUtilIsHostBoot, sceLncUtilIsHostBoot@@0x52960D9404F104A9\n"
    "sceLncUtilIsHostBoot:\n");

asm(".global sceLncUtilIsPs2Emu\n"
    ".type   sceLncUtilIsPs2Emu, @function\n"
    ".symver sceLncUtilIsPs2Emu, sceLncUtilIsPs2Emu@@0x8B8B66ECC07464AD\n"
    "sceLncUtilIsPs2Emu:\n");

asm(".global sceLncUtilIsShellUiFgAndGameBgCpuMode\n"
    ".type   sceLncUtilIsShellUiFgAndGameBgCpuMode, @function\n"
    ".symver sceLncUtilIsShellUiFgAndGameBgCpuMode, sceLncUtilIsShellUiFgAndGameBgCpuMode@@0x472E2EF0AC64558E\n"
    "sceLncUtilIsShellUiFgAndGameBgCpuMode:\n");

asm(".global sceLncUtilIsSpeculativeLaunch\n"
    ".type   sceLncUtilIsSpeculativeLaunch, @function\n"
    ".symver sceLncUtilIsSpeculativeLaunch, sceLncUtilIsSpeculativeLaunch@@0x542C0D48DCB7351D\n"
    "sceLncUtilIsSpeculativeLaunch:\n");

asm(".global sceLncUtilKickCoredumpOnlyProcMem\n"
    ".type   sceLncUtilKickCoredumpOnlyProcMem, @function\n"
    ".symver sceLncUtilKickCoredumpOnlyProcMem, sceLncUtilKickCoredumpOnlyProcMem@@0x80D9FE119B66D62D\n"
    "sceLncUtilKickCoredumpOnlyProcMem:\n");

asm(".global sceLncUtilKillApp\n"
    ".type   sceLncUtilKillApp, @function\n"
    ".symver sceLncUtilKillApp, sceLncUtilKillApp@@0x499DAE1F901BC2CF\n"
    "sceLncUtilKillApp:\n");

asm(".global sceLncUtilKillAppWithReason\n"
    ".type   sceLncUtilKillAppWithReason, @function\n"
    ".symver sceLncUtilKillAppWithReason, sceLncUtilKillAppWithReason@@0x0000000000000000\n"
    "sceLncUtilKillAppWithReason:\n");

asm(".global sceLncUtilKillLocalProcess\n"
    ".type   sceLncUtilKillLocalProcess, @function\n"
    ".symver sceLncUtilKillLocalProcess, sceLncUtilKillLocalProcess@@0x22194B752017F899\n"
    "sceLncUtilKillLocalProcess:\n");

asm(".global sceLncUtilLaunchApp\n"
    ".type   sceLncUtilLaunchApp, @function\n"
    ".symver sceLncUtilLaunchApp, sceLncUtilLaunchApp@@0x00FA7449503EEA0A\n"
    "sceLncUtilLaunchApp:\n");

asm(".global sceLncUtilLoadExec\n"
    ".type   sceLncUtilLoadExec, @function\n"
    ".symver sceLncUtilLoadExec, sceLncUtilLoadExec@@0xC30A513605BCD42B\n"
    "sceLncUtilLoadExec:\n");

asm(".global sceLncUtilNotifyCoredumpRequestEnd\n"
    ".type   sceLncUtilNotifyCoredumpRequestEnd, @function\n"
    ".symver sceLncUtilNotifyCoredumpRequestEnd, sceLncUtilNotifyCoredumpRequestEnd@@0xFBC2C995DF4B22DE\n"
    "sceLncUtilNotifyCoredumpRequestEnd:\n");

asm(".global sceLncUtilNotifyCoredumpRequestProgress\n"
    ".type   sceLncUtilNotifyCoredumpRequestProgress, @function\n"
    ".symver sceLncUtilNotifyCoredumpRequestProgress, sceLncUtilNotifyCoredumpRequestProgress@@0x1CA6662E619F91DE\n"
    "sceLncUtilNotifyCoredumpRequestProgress:\n");

asm(".global sceLncUtilNotifyVshReady\n"
    ".type   sceLncUtilNotifyVshReady, @function\n"
    ".symver sceLncUtilNotifyVshReady, sceLncUtilNotifyVshReady@@0x00DE6A009F129891\n"
    "sceLncUtilNotifyVshReady:\n");

asm(".global sceLncUtilRaiseException\n"
    ".type   sceLncUtilRaiseException, @function\n"
    ".symver sceLncUtilRaiseException, sceLncUtilRaiseException@@0x003F9EB7ADE18087\n"
    "sceLncUtilRaiseException:\n");

asm(".global sceLncUtilRaiseExceptionLocalProcess\n"
    ".type   sceLncUtilRaiseExceptionLocalProcess, @function\n"
    ".symver sceLncUtilRaiseExceptionLocalProcess, sceLncUtilRaiseExceptionLocalProcess@@0x089E390CB450383F\n"
    "sceLncUtilRaiseExceptionLocalProcess:\n");

asm(".global sceLncUtilRegisterCdlgSharedMemoryName\n"
    ".type   sceLncUtilRegisterCdlgSharedMemoryName, @function\n"
    ".symver sceLncUtilRegisterCdlgSharedMemoryName, sceLncUtilRegisterCdlgSharedMemoryName@@0x427E4921123A64D5\n"
    "sceLncUtilRegisterCdlgSharedMemoryName:\n");

asm(".global sceLncUtilRegisterDaemon\n"
    ".type   sceLncUtilRegisterDaemon, @function\n"
    ".symver sceLncUtilRegisterDaemon, sceLncUtilRegisterDaemon@@0x00576E7D53E61AB9\n"
    "sceLncUtilRegisterDaemon:\n");

asm(".global sceLncUtilRegisterShellUI\n"
    ".type   sceLncUtilRegisterShellUI, @function\n"
    ".symver sceLncUtilRegisterShellUI, sceLncUtilRegisterShellUI@@0x6B04BE79856E5C90\n"
    "sceLncUtilRegisterShellUI:\n");

asm(".global sceLncUtilReleaseCpuBudgetOfExtraAudioDevices\n"
    ".type   sceLncUtilReleaseCpuBudgetOfExtraAudioDevices, @function\n"
    ".symver sceLncUtilReleaseCpuBudgetOfExtraAudioDevices, sceLncUtilReleaseCpuBudgetOfExtraAudioDevices@@0x42F5182DD3E1CA54\n"
    "sceLncUtilReleaseCpuBudgetOfExtraAudioDevices:\n");

asm(".global sceLncUtilReleaseCpuBudgetOfImeForBigApp\n"
    ".type   sceLncUtilReleaseCpuBudgetOfImeForBigApp, @function\n"
    ".symver sceLncUtilReleaseCpuBudgetOfImeForBigApp, sceLncUtilReleaseCpuBudgetOfImeForBigApp@@0xD4F4213DDC8D0A3F\n"
    "sceLncUtilReleaseCpuBudgetOfImeForBigApp:\n");

asm(".global sceLncUtilReleaseCpuBudgetOfInGameStore\n"
    ".type   sceLncUtilReleaseCpuBudgetOfInGameStore, @function\n"
    ".symver sceLncUtilReleaseCpuBudgetOfInGameStore, sceLncUtilReleaseCpuBudgetOfInGameStore@@0x42C2E167EF16BD23\n"
    "sceLncUtilReleaseCpuBudgetOfInGameStore:\n");

asm(".global sceLncUtilResumeApp\n"
    ".type   sceLncUtilResumeApp, @function\n"
    ".symver sceLncUtilResumeApp, sceLncUtilResumeApp@@0x00943937843865A8\n"
    "sceLncUtilResumeApp:\n");

asm(".global sceLncUtilResumeLocalProcess\n"
    ".type   sceLncUtilResumeLocalProcess, @function\n"
    ".symver sceLncUtilResumeLocalProcess, sceLncUtilResumeLocalProcess@@0x005DA0BDB0DAF6BB\n"
    "sceLncUtilResumeLocalProcess:\n");

asm(".global sceLncUtilSetAppFocus\n"
    ".type   sceLncUtilSetAppFocus, @function\n"
    ".symver sceLncUtilSetAppFocus, sceLncUtilSetAppFocus@@0xBFB0D8B97D06E534\n"
    "sceLncUtilSetAppFocus:\n");

asm(".global sceLncUtilSetCdlgExec\n"
    ".type   sceLncUtilSetCdlgExec, @function\n"
    ".symver sceLncUtilSetCdlgExec, sceLncUtilSetCdlgExec@@0xDE61EE285EDFB1DF\n"
    "sceLncUtilSetCdlgExec:\n");

asm(".global sceLncUtilSetControllerFocus\n"
    ".type   sceLncUtilSetControllerFocus, @function\n"
    ".symver sceLncUtilSetControllerFocus, sceLncUtilSetControllerFocus@@0x5FC8186F22C6D709\n"
    "sceLncUtilSetControllerFocus:\n");

asm(".global sceLncUtilSetControllerFocusPermission\n"
    ".type   sceLncUtilSetControllerFocusPermission, @function\n"
    ".symver sceLncUtilSetControllerFocusPermission, sceLncUtilSetControllerFocusPermission@@0x34960041E3F7CFB7\n"
    "sceLncUtilSetControllerFocusPermission:\n");

asm(".global sceLncUtilStartKillApp\n"
    ".type   sceLncUtilStartKillApp, @function\n"
    ".symver sceLncUtilStartKillApp, sceLncUtilStartKillApp@@0x00DFEEB8CDC9014B\n"
    "sceLncUtilStartKillApp:\n");

asm(".global sceLncUtilStartLaunchAppByTitleId\n"
    ".type   sceLncUtilStartLaunchAppByTitleId, @function\n"
    ".symver sceLncUtilStartLaunchAppByTitleId, sceLncUtilStartLaunchAppByTitleId@@0xAF4EEF0F848FDAC7\n"
    "sceLncUtilStartLaunchAppByTitleId:\n");

asm(".global sceLncUtilSuspendApp\n"
    ".type   sceLncUtilSuspendApp, @function\n"
    ".symver sceLncUtilSuspendApp, sceLncUtilSuspendApp@@0x63CA274188EEBCE5\n"
    "sceLncUtilSuspendApp:\n");

asm(".global sceLncUtilSuspendBackgroundApp\n"
    ".type   sceLncUtilSuspendBackgroundApp, @function\n"
    ".symver sceLncUtilSuspendBackgroundApp, sceLncUtilSuspendBackgroundApp@@0x00F2F61791D5E685\n"
    "sceLncUtilSuspendBackgroundApp:\n");

asm(".global sceLncUtilSuspendLocalProcess\n"
    ".type   sceLncUtilSuspendLocalProcess, @function\n"
    ".symver sceLncUtilSuspendLocalProcess, sceLncUtilSuspendLocalProcess@@0x00ADDF92CCBDB4D8\n"
    "sceLncUtilSuspendLocalProcess:\n");

asm(".global sceLncUtilTerminate\n"
    ".type   sceLncUtilTerminate, @function\n"
    ".symver sceLncUtilTerminate, sceLncUtilTerminate@@0x702A1DF81DC47612\n"
    "sceLncUtilTerminate:\n");

asm(".global sceLncUtilTryBlockAppSuspend\n"
    ".type   sceLncUtilTryBlockAppSuspend, @function\n"
    ".symver sceLncUtilTryBlockAppSuspend, sceLncUtilTryBlockAppSuspend@@0x009AC5A1A75534CE\n"
    "sceLncUtilTryBlockAppSuspend:\n");

asm(".global sceLncUtilUnblockAppSuspend\n"
    ".type   sceLncUtilUnblockAppSuspend, @function\n"
    ".symver sceLncUtilUnblockAppSuspend, sceLncUtilUnblockAppSuspend@@0x89165DB98215D61B\n"
    "sceLncUtilUnblockAppSuspend:\n");

asm(".global sceLncUtilUnregisterCdlgSharedMemoryName\n"
    ".type   sceLncUtilUnregisterCdlgSharedMemoryName, @function\n"
    ".symver sceLncUtilUnregisterCdlgSharedMemoryName, sceLncUtilUnregisterCdlgSharedMemoryName@@0x69544DA759CE38A6\n"
    "sceLncUtilUnregisterCdlgSharedMemoryName:\n");

asm(".global sceLncUtilUnregisterDaemon\n"
    ".type   sceLncUtilUnregisterDaemon, @function\n"
    ".symver sceLncUtilUnregisterDaemon, sceLncUtilUnregisterDaemon@@0x06731A5B9C1F9E54\n"
    "sceLncUtilUnregisterDaemon:\n");

asm(".global sceLncUtilUnregisterShellUI\n"
    ".type   sceLncUtilUnregisterShellUI, @function\n"
    ".symver sceLncUtilUnregisterShellUI, sceLncUtilUnregisterShellUI@@0x72ABA2E09509B5B6\n"
    "sceLncUtilUnregisterShellUI:\n");

asm(".global sceShellCoreUtilAccessibilityZoomLock\n"
    ".type   sceShellCoreUtilAccessibilityZoomLock, @function\n"
    ".symver sceShellCoreUtilAccessibilityZoomLock, sceShellCoreUtilAccessibilityZoomLock@@0xE527CCB6C5BC87B0\n"
    "sceShellCoreUtilAccessibilityZoomLock:\n");

asm(".global sceShellCoreUtilAccessibilityZoomUnlock\n"
    ".type   sceShellCoreUtilAccessibilityZoomUnlock, @function\n"
    ".symver sceShellCoreUtilAccessibilityZoomUnlock, sceShellCoreUtilAccessibilityZoomUnlock@@0x524BB6269666A2A7\n"
    "sceShellCoreUtilAccessibilityZoomUnlock:\n");

asm(".global sceShellCoreUtilAcquireBgmCpuBudget\n"
    ".type   sceShellCoreUtilAcquireBgmCpuBudget, @function\n"
    ".symver sceShellCoreUtilAcquireBgmCpuBudget, sceShellCoreUtilAcquireBgmCpuBudget@@0x00A9504D867A94CF\n"
    "sceShellCoreUtilAcquireBgmCpuBudget:\n");

asm(".global sceShellCoreUtilAcquireRemotePlayCpuBudget\n"
    ".type   sceShellCoreUtilAcquireRemotePlayCpuBudget, @function\n"
    ".symver sceShellCoreUtilAcquireRemotePlayCpuBudget, sceShellCoreUtilAcquireRemotePlayCpuBudget@@0x4DF547A11557D873\n"
    "sceShellCoreUtilAcquireRemotePlayCpuBudget:\n");

asm(".global sceShellCoreUtilAcquireSharePlayCpuBudget\n"
    ".type   sceShellCoreUtilAcquireSharePlayCpuBudget, @function\n"
    ".symver sceShellCoreUtilAcquireSharePlayCpuBudget, sceShellCoreUtilAcquireSharePlayCpuBudget@@0x7C1BAE91E199D851\n"
    "sceShellCoreUtilAcquireSharePlayCpuBudget:\n");

asm(".global sceShellCoreUtilActivateAbort\n"
    ".type   sceShellCoreUtilActivateAbort, @function\n"
    ".symver sceShellCoreUtilActivateAbort, sceShellCoreUtilActivateAbort@@0x9A992887256A0913\n"
    "sceShellCoreUtilActivateAbort:\n");

asm(".global sceShellCoreUtilActivateGetStatus\n"
    ".type   sceShellCoreUtilActivateGetStatus, @function\n"
    ".symver sceShellCoreUtilActivateGetStatus, sceShellCoreUtilActivateGetStatus@@0x7E470CE5872A8D5F\n"
    "sceShellCoreUtilActivateGetStatus:\n");

asm(".global sceShellCoreUtilActivateInit\n"
    ".type   sceShellCoreUtilActivateInit, @function\n"
    ".symver sceShellCoreUtilActivateInit, sceShellCoreUtilActivateInit@@0xC7986A2912B38985\n"
    "sceShellCoreUtilActivateInit:\n");

asm(".global sceShellCoreUtilActivateIsActivated\n"
    ".type   sceShellCoreUtilActivateIsActivated, @function\n"
    ".symver sceShellCoreUtilActivateIsActivated, sceShellCoreUtilActivateIsActivated@@0x8E4B42310360C857\n"
    "sceShellCoreUtilActivateIsActivated:\n");

asm(".global sceShellCoreUtilActivateRecordActivation\n"
    ".type   sceShellCoreUtilActivateRecordActivation, @function\n"
    ".symver sceShellCoreUtilActivateRecordActivation, sceShellCoreUtilActivateRecordActivation@@0xC48302959673E749\n"
    "sceShellCoreUtilActivateRecordActivation:\n");

asm(".global sceShellCoreUtilActivateStart\n"
    ".type   sceShellCoreUtilActivateStart, @function\n"
    ".symver sceShellCoreUtilActivateStart, sceShellCoreUtilActivateStart@@0x003115672EC9C644\n"
    "sceShellCoreUtilActivateStart:\n");

asm(".global sceShellCoreUtilActivateStartAsync\n"
    ".type   sceShellCoreUtilActivateStartAsync, @function\n"
    ".symver sceShellCoreUtilActivateStartAsync, sceShellCoreUtilActivateStartAsync@@0x099ACE1EAB7AA026\n"
    "sceShellCoreUtilActivateStartAsync:\n");

asm(".global sceShellCoreUtilActivateTerm\n"
    ".type   sceShellCoreUtilActivateTerm, @function\n"
    ".symver sceShellCoreUtilActivateTerm, sceShellCoreUtilActivateTerm@@0x89B5E1F8C738C1BB\n"
    "sceShellCoreUtilActivateTerm:\n");

asm(".global sceShellCoreUtilChangeRunLevel\n"
    ".type   sceShellCoreUtilChangeRunLevel, @function\n"
    ".symver sceShellCoreUtilChangeRunLevel, sceShellCoreUtilChangeRunLevel@@0xC2D34487513D00B0\n"
    "sceShellCoreUtilChangeRunLevel:\n");

asm(".global sceShellCoreUtilChangeToStaffModeForIDU\n"
    ".type   sceShellCoreUtilChangeToStaffModeForIDU, @function\n"
    ".symver sceShellCoreUtilChangeToStaffModeForIDU, sceShellCoreUtilChangeToStaffModeForIDU@@0xBFCD5D7E768C7D46\n"
    "sceShellCoreUtilChangeToStaffModeForIDU:\n");

asm(".global sceShellCoreUtilCheckerAbort\n"
    ".type   sceShellCoreUtilCheckerAbort, @function\n"
    ".symver sceShellCoreUtilCheckerAbort, sceShellCoreUtilCheckerAbort@@0xF550F363B9B534DF\n"
    "sceShellCoreUtilCheckerAbort:\n");

asm(".global sceShellCoreUtilCleanupCrashReport\n"
    ".type   sceShellCoreUtilCleanupCrashReport, @function\n"
    ".symver sceShellCoreUtilCleanupCrashReport, sceShellCoreUtilCleanupCrashReport@@0x020612180406B57B\n"
    "sceShellCoreUtilCleanupCrashReport:\n");

asm(".global sceShellCoreUtilClearAppData\n"
    ".type   sceShellCoreUtilClearAppData, @function\n"
    ".symver sceShellCoreUtilClearAppData, sceShellCoreUtilClearAppData@@0x9796DD838B544C67\n"
    "sceShellCoreUtilClearAppData:\n");

asm(".global sceShellCoreUtilClearPs4AppCategoryDefaultsListUpdate\n"
    ".type   sceShellCoreUtilClearPs4AppCategoryDefaultsListUpdate, @function\n"
    ".symver sceShellCoreUtilClearPs4AppCategoryDefaultsListUpdate, sceShellCoreUtilClearPs4AppCategoryDefaultsListUpdate@@0x0AB240A8702577D3\n"
    "sceShellCoreUtilClearPs4AppCategoryDefaultsListUpdate:\n");

asm(".global sceShellCoreUtilClearPsnAccountInfo\n"
    ".type   sceShellCoreUtilClearPsnAccountInfo, @function\n"
    ".symver sceShellCoreUtilClearPsnAccountInfo, sceShellCoreUtilClearPsnAccountInfo@@0x4676361D3C2ACF70\n"
    "sceShellCoreUtilClearPsnAccountInfo:\n");

asm(".global sceShellCoreUtilCrashReportRequestCancel\n"
    ".type   sceShellCoreUtilCrashReportRequestCancel, @function\n"
    ".symver sceShellCoreUtilCrashReportRequestCancel, sceShellCoreUtilCrashReportRequestCancel@@0x49848BE0AB737005\n"
    "sceShellCoreUtilCrashReportRequestCancel:\n");

asm(".global sceShellCoreUtilDeclareBeginOfExternalStorageAppMove\n"
    ".type   sceShellCoreUtilDeclareBeginOfExternalStorageAppMove, @function\n"
    ".symver sceShellCoreUtilDeclareBeginOfExternalStorageAppMove, sceShellCoreUtilDeclareBeginOfExternalStorageAppMove@@0x29308F2AABC54E89\n"
    "sceShellCoreUtilDeclareBeginOfExternalStorageAppMove:\n");

asm(".global sceShellCoreUtilDeclareEndOfExternalStorageAppMove\n"
    ".type   sceShellCoreUtilDeclareEndOfExternalStorageAppMove, @function\n"
    ".symver sceShellCoreUtilDeclareEndOfExternalStorageAppMove, sceShellCoreUtilDeclareEndOfExternalStorageAppMove@@0x176D3103536C1BDB\n"
    "sceShellCoreUtilDeclareEndOfExternalStorageAppMove:\n");

asm(".global sceShellCoreUtilDeleteDiscInstalledTitleWorkaroundFile\n"
    ".type   sceShellCoreUtilDeleteDiscInstalledTitleWorkaroundFile, @function\n"
    ".symver sceShellCoreUtilDeleteDiscInstalledTitleWorkaroundFile, sceShellCoreUtilDeleteDiscInstalledTitleWorkaroundFile@@0x5E5701AA1C9A2722\n"
    "sceShellCoreUtilDeleteDiscInstalledTitleWorkaroundFile:\n");

asm(".global sceShellCoreUtilDeleteDownloadedHidConfigFile\n"
    ".type   sceShellCoreUtilDeleteDownloadedHidConfigFile, @function\n"
    ".symver sceShellCoreUtilDeleteDownloadedHidConfigFile, sceShellCoreUtilDeleteDownloadedHidConfigFile@@0xC8EECE214E395274\n"
    "sceShellCoreUtilDeleteDownloadedHidConfigFile:\n");

asm(".global sceShellCoreUtilDeleteDownloadedNetEvConfigFile\n"
    ".type   sceShellCoreUtilDeleteDownloadedNetEvConfigFile, @function\n"
    ".symver sceShellCoreUtilDeleteDownloadedNetEvConfigFile, sceShellCoreUtilDeleteDownloadedNetEvConfigFile@@0xE1280B6C93D4C4DC\n"
    "sceShellCoreUtilDeleteDownloadedNetEvConfigFile:\n");

asm(".global sceShellCoreUtilDeleteDownloadedTitleWorkaroundFile\n"
    ".type   sceShellCoreUtilDeleteDownloadedTitleWorkaroundFile, @function\n"
    ".symver sceShellCoreUtilDeleteDownloadedTitleWorkaroundFile, sceShellCoreUtilDeleteDownloadedTitleWorkaroundFile@@0x72D4D82FD9689AFF\n"
    "sceShellCoreUtilDeleteDownloadedTitleWorkaroundFile:\n");

asm(".global sceShellCoreUtilDoFsck\n"
    ".type   sceShellCoreUtilDoFsck, @function\n"
    ".symver sceShellCoreUtilDoFsck, sceShellCoreUtilDoFsck@@0xD103780549F3175E\n"
    "sceShellCoreUtilDoFsck:\n");

asm(".global sceShellCoreUtilDownloadHidConfigFileFromServer\n"
    ".type   sceShellCoreUtilDownloadHidConfigFileFromServer, @function\n"
    ".symver sceShellCoreUtilDownloadHidConfigFileFromServer, sceShellCoreUtilDownloadHidConfigFileFromServer@@0x58DD6FDF1628183C\n"
    "sceShellCoreUtilDownloadHidConfigFileFromServer:\n");

asm(".global sceShellCoreUtilDownloadNetEvConfigFileFromServer\n"
    ".type   sceShellCoreUtilDownloadNetEvConfigFileFromServer, @function\n"
    ".symver sceShellCoreUtilDownloadNetEvConfigFileFromServer, sceShellCoreUtilDownloadNetEvConfigFileFromServer@@0x037C1B6CB9AB415E\n"
    "sceShellCoreUtilDownloadNetEvConfigFileFromServer:\n");

asm(".global sceShellCoreUtilDownloadTitleWorkaroundFileFromServer\n"
    ".type   sceShellCoreUtilDownloadTitleWorkaroundFileFromServer, @function\n"
    ".symver sceShellCoreUtilDownloadTitleWorkaroundFileFromServer, sceShellCoreUtilDownloadTitleWorkaroundFileFromServer@@0xE583675F93DFAAEA\n"
    "sceShellCoreUtilDownloadTitleWorkaroundFileFromServer:\n");

asm(".global sceShellCoreUtilEndUmmDictation\n"
    ".type   sceShellCoreUtilEndUmmDictation, @function\n"
    ".symver sceShellCoreUtilEndUmmDictation, sceShellCoreUtilEndUmmDictation@@0x8A49A479ECFC0139\n"
    "sceShellCoreUtilEndUmmDictation:\n");

asm(".global sceShellCoreUtilEnterPowerLockSection\n"
    ".type   sceShellCoreUtilEnterPowerLockSection, @function\n"
    ".symver sceShellCoreUtilEnterPowerLockSection, sceShellCoreUtilEnterPowerLockSection@@0xF69959082466F71E\n"
    "sceShellCoreUtilEnterPowerLockSection:\n");

asm(".global sceShellCoreUtilExecuteCrashReport\n"
    ".type   sceShellCoreUtilExecuteCrashReport, @function\n"
    ".symver sceShellCoreUtilExecuteCrashReport, sceShellCoreUtilExecuteCrashReport@@0x48E9B246A4692883\n"
    "sceShellCoreUtilExecuteCrashReport:\n");

asm(".global sceShellCoreUtilExfatFormatExternalHdd\n"
    ".type   sceShellCoreUtilExfatFormatExternalHdd, @function\n"
    ".symver sceShellCoreUtilExfatFormatExternalHdd, sceShellCoreUtilExfatFormatExternalHdd@@0xFA355A2921B49C79\n"
    "sceShellCoreUtilExfatFormatExternalHdd:\n");

asm(".global sceShellCoreUtilExitApp\n"
    ".type   sceShellCoreUtilExitApp, @function\n"
    ".symver sceShellCoreUtilExitApp, sceShellCoreUtilExitApp@@0x867BE2DCB8157833\n"
    "sceShellCoreUtilExitApp:\n");

asm(".global sceShellCoreUtilExitMiniApp\n"
    ".type   sceShellCoreUtilExitMiniApp, @function\n"
    ".symver sceShellCoreUtilExitMiniApp, sceShellCoreUtilExitMiniApp@@0x00D20EAE8782533F\n"
    "sceShellCoreUtilExitMiniApp:\n");

asm(".global sceShellCoreUtilExitMiniAppWithValue\n"
    ".type   sceShellCoreUtilExitMiniAppWithValue, @function\n"
    ".symver sceShellCoreUtilExitMiniAppWithValue, sceShellCoreUtilExitMiniAppWithValue@@0x76DC79B5C1855482\n"
    "sceShellCoreUtilExitMiniAppWithValue:\n");

asm(".global sceShellCoreUtilFormatExternalHdd\n"
    ".type   sceShellCoreUtilFormatExternalHdd, @function\n"
    ".symver sceShellCoreUtilFormatExternalHdd, sceShellCoreUtilFormatExternalHdd@@0x0000000000000000\n"
    "sceShellCoreUtilFormatExternalHdd:\n");

asm(".global sceShellCoreUtilFormatHddForRestore\n"
    ".type   sceShellCoreUtilFormatHddForRestore, @function\n"
    ".symver sceShellCoreUtilFormatHddForRestore, sceShellCoreUtilFormatHddForRestore@@0x2E51667EB9298D6D\n"
    "sceShellCoreUtilFormatHddForRestore:\n");

asm(".global sceShellCoreUtilGetAppData\n"
    ".type   sceShellCoreUtilGetAppData, @function\n"
    ".symver sceShellCoreUtilGetAppData, sceShellCoreUtilGetAppData@@0x0000000000000000\n"
    "sceShellCoreUtilGetAppData:\n");

asm(".global sceShellCoreUtilGetAppEnableTTS\n"
    ".type   sceShellCoreUtilGetAppEnableTTS, @function\n"
    ".symver sceShellCoreUtilGetAppEnableTTS, sceShellCoreUtilGetAppEnableTTS@@0x5C6C574B5DF9591F\n"
    "sceShellCoreUtilGetAppEnableTTS:\n");

asm(".global sceShellCoreUtilGetAppEnterButtonAssign\n"
    ".type   sceShellCoreUtilGetAppEnterButtonAssign, @function\n"
    ".symver sceShellCoreUtilGetAppEnterButtonAssign, sceShellCoreUtilGetAppEnterButtonAssign@@0x57D6F71DF375F6F3\n"
    "sceShellCoreUtilGetAppEnterButtonAssign:\n");

asm(".global sceShellCoreUtilGetAppLaunchTypeInfo\n"
    ".type   sceShellCoreUtilGetAppLaunchTypeInfo, @function\n"
    ".symver sceShellCoreUtilGetAppLaunchTypeInfo, sceShellCoreUtilGetAppLaunchTypeInfo@@0x64828693EDF95035\n"
    "sceShellCoreUtilGetAppLaunchTypeInfo:\n");

asm(".global sceShellCoreUtilGetAppLaunchedParamInt\n"
    ".type   sceShellCoreUtilGetAppLaunchedParamInt, @function\n"
    ".symver sceShellCoreUtilGetAppLaunchedParamInt, sceShellCoreUtilGetAppLaunchedParamInt@@0x00BB8EF86C0EEE97\n"
    "sceShellCoreUtilGetAppLaunchedParamInt:\n");

asm(".global sceShellCoreUtilGetAppLaunchedParamIntByBudgetType\n"
    ".type   sceShellCoreUtilGetAppLaunchedParamIntByBudgetType, @function\n"
    ".symver sceShellCoreUtilGetAppLaunchedParamIntByBudgetType, sceShellCoreUtilGetAppLaunchedParamIntByBudgetType@@0x93214E6B149A3F40\n"
    "sceShellCoreUtilGetAppLaunchedParamIntByBudgetType:\n");

asm(".global sceShellCoreUtilGetAppLaunchedParamString\n"
    ".type   sceShellCoreUtilGetAppLaunchedParamString, @function\n"
    ".symver sceShellCoreUtilGetAppLaunchedParamString, sceShellCoreUtilGetAppLaunchedParamString@@0x7F967B1487A81DDC\n"
    "sceShellCoreUtilGetAppLaunchedParamString:\n");

asm(".global sceShellCoreUtilGetAppLaunchedParamStringByBudgetType\n"
    ".type   sceShellCoreUtilGetAppLaunchedParamStringByBudgetType, @function\n"
    ".symver sceShellCoreUtilGetAppLaunchedParamStringByBudgetType, sceShellCoreUtilGetAppLaunchedParamStringByBudgetType@@0x759DD17C3CE09826\n"
    "sceShellCoreUtilGetAppLaunchedParamStringByBudgetType:\n");

asm(".global sceShellCoreUtilGetAutoPowerDownRemainingSeconds\n"
    ".type   sceShellCoreUtilGetAutoPowerDownRemainingSeconds, @function\n"
    ".symver sceShellCoreUtilGetAutoPowerDownRemainingSeconds, sceShellCoreUtilGetAutoPowerDownRemainingSeconds@@0xE602152338A982CC\n"
    "sceShellCoreUtilGetAutoPowerDownRemainingSeconds:\n");

asm(".global sceShellCoreUtilGetBasicProductShape\n"
    ".type   sceShellCoreUtilGetBasicProductShape, @function\n"
    ".symver sceShellCoreUtilGetBasicProductShape, sceShellCoreUtilGetBasicProductShape@@0x940BD2ACA023C420\n"
    "sceShellCoreUtilGetBasicProductShape:\n");

asm(".global sceShellCoreUtilGetCheckerString\n"
    ".type   sceShellCoreUtilGetCheckerString, @function\n"
    ".symver sceShellCoreUtilGetCheckerString, sceShellCoreUtilGetCheckerString@@0x1307D245A3E5084E\n"
    "sceShellCoreUtilGetCheckerString:\n");

asm(".global sceShellCoreUtilGetCheckerStringEx\n"
    ".type   sceShellCoreUtilGetCheckerStringEx, @function\n"
    ".symver sceShellCoreUtilGetCheckerStringEx, sceShellCoreUtilGetCheckerStringEx@@0x800C93E369F01253\n"
    "sceShellCoreUtilGetCheckerStringEx:\n");

asm(".global sceShellCoreUtilGetCloudClientStatus\n"
    ".type   sceShellCoreUtilGetCloudClientStatus, @function\n"
    ".symver sceShellCoreUtilGetCloudClientStatus, sceShellCoreUtilGetCloudClientStatus@@0x320DCFD59E176AFB\n"
    "sceShellCoreUtilGetCloudClientStatus:\n");

asm(".global sceShellCoreUtilGetCrashReportCoreFileSetSize\n"
    ".type   sceShellCoreUtilGetCrashReportCoreFileSetSize, @function\n"
    ".symver sceShellCoreUtilGetCrashReportCoreFileSetSize, sceShellCoreUtilGetCrashReportCoreFileSetSize@@0x15C02178A3BCBBB7\n"
    "sceShellCoreUtilGetCrashReportCoreFileSetSize:\n");

asm(".global sceShellCoreUtilGetCrashReportFilterInfoStart\n"
    ".type   sceShellCoreUtilGetCrashReportFilterInfoStart, @function\n"
    ".symver sceShellCoreUtilGetCrashReportFilterInfoStart, sceShellCoreUtilGetCrashReportFilterInfoStart@@0x8C227E824B38F370\n"
    "sceShellCoreUtilGetCrashReportFilterInfoStart:\n");

asm(".global sceShellCoreUtilGetCrashReportInfoForBoot\n"
    ".type   sceShellCoreUtilGetCrashReportInfoForBoot, @function\n"
    ".symver sceShellCoreUtilGetCrashReportInfoForBoot, sceShellCoreUtilGetCrashReportInfoForBoot@@0x0044E0007A79F85E\n"
    "sceShellCoreUtilGetCrashReportInfoForBoot:\n");

asm(".global sceShellCoreUtilGetCrashReportInfoForBootStart\n"
    ".type   sceShellCoreUtilGetCrashReportInfoForBootStart, @function\n"
    ".symver sceShellCoreUtilGetCrashReportInfoForBootStart, sceShellCoreUtilGetCrashReportInfoForBootStart@@0x57D2DA748BEEE4AA\n"
    "sceShellCoreUtilGetCrashReportInfoForBootStart:\n");

asm(".global sceShellCoreUtilGetCrashReportInfoStart\n"
    ".type   sceShellCoreUtilGetCrashReportInfoStart, @function\n"
    ".symver sceShellCoreUtilGetCrashReportInfoStart, sceShellCoreUtilGetCrashReportInfoStart@@0x27938F00B14D7451\n"
    "sceShellCoreUtilGetCrashReportInfoStart:\n");

asm(".global sceShellCoreUtilGetCrashReportResult\n"
    ".type   sceShellCoreUtilGetCrashReportResult, @function\n"
    ".symver sceShellCoreUtilGetCrashReportResult, sceShellCoreUtilGetCrashReportResult@@0x353B6D0650F65DB9\n"
    "sceShellCoreUtilGetCrashReportResult:\n");

asm(".global sceShellCoreUtilGetCrashReportStatus\n"
    ".type   sceShellCoreUtilGetCrashReportStatus, @function\n"
    ".symver sceShellCoreUtilGetCrashReportStatus, sceShellCoreUtilGetCrashReportStatus@@0x00E18430F57C27EE\n"
    "sceShellCoreUtilGetCrashReportStatus:\n");

asm(".global sceShellCoreUtilGetCrashReportUploadStatus\n"
    ".type   sceShellCoreUtilGetCrashReportUploadStatus, @function\n"
    ".symver sceShellCoreUtilGetCrashReportUploadStatus, sceShellCoreUtilGetCrashReportUploadStatus@@0x2FA4748D4EF24D34\n"
    "sceShellCoreUtilGetCrashReportUploadStatus:\n");

asm(".global sceShellCoreUtilGetDeviceIndexBehavior\n"
    ".type   sceShellCoreUtilGetDeviceIndexBehavior, @function\n"
    ".symver sceShellCoreUtilGetDeviceIndexBehavior, sceShellCoreUtilGetDeviceIndexBehavior@@0xA083474EA535AAF6\n"
    "sceShellCoreUtilGetDeviceIndexBehavior:\n");

asm(".global sceShellCoreUtilGetDeviceIndexBehaviorWithTimeout\n"
    ".type   sceShellCoreUtilGetDeviceIndexBehaviorWithTimeout, @function\n"
    ".symver sceShellCoreUtilGetDeviceIndexBehaviorWithTimeout, sceShellCoreUtilGetDeviceIndexBehaviorWithTimeout@@0xBCFC4AA1CE4CCB14\n"
    "sceShellCoreUtilGetDeviceIndexBehaviorWithTimeout:\n");

asm(".global sceShellCoreUtilGetEffectiveTotalSizeOfUserPartition\n"
    ".type   sceShellCoreUtilGetEffectiveTotalSizeOfUserPartition, @function\n"
    ".symver sceShellCoreUtilGetEffectiveTotalSizeOfUserPartition, sceShellCoreUtilGetEffectiveTotalSizeOfUserPartition@@0x00AE45796E9E3DD2\n"
    "sceShellCoreUtilGetEffectiveTotalSizeOfUserPartition:\n");

asm(".global sceShellCoreUtilGetFreeSizeOfAvContentsTmp\n"
    ".type   sceShellCoreUtilGetFreeSizeOfAvContentsTmp, @function\n"
    ".symver sceShellCoreUtilGetFreeSizeOfAvContentsTmp, sceShellCoreUtilGetFreeSizeOfAvContentsTmp@@0x82E7FEC5C32809AB\n"
    "sceShellCoreUtilGetFreeSizeOfAvContentsTmp:\n");

asm(".global sceShellCoreUtilGetFreeSizeOfUserPartition\n"
    ".type   sceShellCoreUtilGetFreeSizeOfUserPartition, @function\n"
    ".symver sceShellCoreUtilGetFreeSizeOfUserPartition, sceShellCoreUtilGetFreeSizeOfUserPartition@@0x65B6392F1987EAE0\n"
    "sceShellCoreUtilGetFreeSizeOfUserPartition:\n");

asm(".global sceShellCoreUtilGetFsckProgress\n"
    ".type   sceShellCoreUtilGetFsckProgress, @function\n"
    ".symver sceShellCoreUtilGetFsckProgress, sceShellCoreUtilGetFsckProgress@@0xD6A6D41579415C5C\n"
    "sceShellCoreUtilGetFsckProgress:\n");

asm(".global sceShellCoreUtilGetGameLiveStreamingStatus\n"
    ".type   sceShellCoreUtilGetGameLiveStreamingStatus, @function\n"
    ".symver sceShellCoreUtilGetGameLiveStreamingStatus, sceShellCoreUtilGetGameLiveStreamingStatus@@0x00834A4167625D01\n"
    "sceShellCoreUtilGetGameLiveStreamingStatus:\n");

asm(".global sceShellCoreUtilGetGnmCompositorOnScreenProfilerFlag\n"
    ".type   sceShellCoreUtilGetGnmCompositorOnScreenProfilerFlag, @function\n"
    ".symver sceShellCoreUtilGetGnmCompositorOnScreenProfilerFlag, sceShellCoreUtilGetGnmCompositorOnScreenProfilerFlag@@0x83C4F8C74183F56A\n"
    "sceShellCoreUtilGetGnmCompositorOnScreenProfilerFlag:\n");

asm(".global sceShellCoreUtilGetGpuLoadEmulationMode\n"
    ".type   sceShellCoreUtilGetGpuLoadEmulationMode, @function\n"
    ".symver sceShellCoreUtilGetGpuLoadEmulationMode, sceShellCoreUtilGetGpuLoadEmulationMode@@0x6DE43DD12C7A73C8\n"
    "sceShellCoreUtilGetGpuLoadEmulationMode:\n");

asm(".global sceShellCoreUtilGetGpuLoadEmulationModeByAppId\n"
    ".type   sceShellCoreUtilGetGpuLoadEmulationModeByAppId, @function\n"
    ".symver sceShellCoreUtilGetGpuLoadEmulationModeByAppId, sceShellCoreUtilGetGpuLoadEmulationModeByAppId@@0x9ECF0757356A68DA\n"
    "sceShellCoreUtilGetGpuLoadEmulationModeByAppId:\n");

asm(".global sceShellCoreUtilGetHidConfigFileInfoString\n"
    ".type   sceShellCoreUtilGetHidConfigFileInfoString, @function\n"
    ".symver sceShellCoreUtilGetHidConfigFileInfoString, sceShellCoreUtilGetHidConfigFileInfoString@@0x00927DEF04E4E0A2\n"
    "sceShellCoreUtilGetHidConfigFileInfoString:\n");

asm(".global sceShellCoreUtilGetHidConfigFileString\n"
    ".type   sceShellCoreUtilGetHidConfigFileString, @function\n"
    ".symver sceShellCoreUtilGetHidConfigFileString, sceShellCoreUtilGetHidConfigFileString@@0xF7B2F40F7FA20431\n"
    "sceShellCoreUtilGetHidConfigFileString:\n");

asm(".global sceShellCoreUtilGetHidConfigName\n"
    ".type   sceShellCoreUtilGetHidConfigName, @function\n"
    ".symver sceShellCoreUtilGetHidConfigName, sceShellCoreUtilGetHidConfigName@@0x0035958B1A298395\n"
    "sceShellCoreUtilGetHidConfigName:\n");

asm(".global sceShellCoreUtilGetHidConfigNum\n"
    ".type   sceShellCoreUtilGetHidConfigNum, @function\n"
    ".symver sceShellCoreUtilGetHidConfigNum, sceShellCoreUtilGetHidConfigNum@@0x44CD576F91DCAB8C\n"
    "sceShellCoreUtilGetHidConfigNum:\n");

asm(".global sceShellCoreUtilGetIDUMode\n"
    ".type   sceShellCoreUtilGetIDUMode, @function\n"
    ".symver sceShellCoreUtilGetIDUMode, sceShellCoreUtilGetIDUMode@@0xF77B6B6DE363C7B7\n"
    "sceShellCoreUtilGetIDUMode:\n");

asm(".global sceShellCoreUtilGetImposeMenuFlagForPs2Emu\n"
    ".type   sceShellCoreUtilGetImposeMenuFlagForPs2Emu, @function\n"
    ".symver sceShellCoreUtilGetImposeMenuFlagForPs2Emu, sceShellCoreUtilGetImposeMenuFlagForPs2Emu@@0x01CDC8F35BBD932E\n"
    "sceShellCoreUtilGetImposeMenuFlagForPs2Emu:\n");

asm(".global sceShellCoreUtilGetManifestFileStatus\n"
    ".type   sceShellCoreUtilGetManifestFileStatus, @function\n"
    ".symver sceShellCoreUtilGetManifestFileStatus, sceShellCoreUtilGetManifestFileStatus@@0xDFD95EC169F9F86D\n"
    "sceShellCoreUtilGetManifestFileStatus:\n");

asm(".global sceShellCoreUtilGetNeedSizeOfAppContent\n"
    ".type   sceShellCoreUtilGetNeedSizeOfAppContent, @function\n"
    ".symver sceShellCoreUtilGetNeedSizeOfAppContent, sceShellCoreUtilGetNeedSizeOfAppContent@@0x92E12B2075D62297\n"
    "sceShellCoreUtilGetNeedSizeOfAppContent:\n");

asm(".global sceShellCoreUtilGetNetEvConfigFileInfoString\n"
    ".type   sceShellCoreUtilGetNetEvConfigFileInfoString, @function\n"
    ".symver sceShellCoreUtilGetNetEvConfigFileInfoString, sceShellCoreUtilGetNetEvConfigFileInfoString@@0x00C05BE0A8A5D3D1\n"
    "sceShellCoreUtilGetNetEvConfigFileInfoString:\n");

asm(".global sceShellCoreUtilGetOutOfVrPlayZoneWarning\n"
    ".type   sceShellCoreUtilGetOutOfVrPlayZoneWarning, @function\n"
    ".symver sceShellCoreUtilGetOutOfVrPlayZoneWarning, sceShellCoreUtilGetOutOfVrPlayZoneWarning@@0xA8450906C07BC8C9\n"
    "sceShellCoreUtilGetOutOfVrPlayZoneWarning:\n");

asm(".global sceShellCoreUtilGetPapcGamePcl\n"
    ".type   sceShellCoreUtilGetPapcGamePcl, @function\n"
    ".symver sceShellCoreUtilGetPapcGamePcl, sceShellCoreUtilGetPapcGamePcl@@0x9606DDBD3DFA9131\n"
    "sceShellCoreUtilGetPapcGamePcl:\n");

asm(".global sceShellCoreUtilGetPbtcUserInfoList\n"
    ".type   sceShellCoreUtilGetPbtcUserInfoList, @function\n"
    ".symver sceShellCoreUtilGetPbtcUserInfoList, sceShellCoreUtilGetPbtcUserInfoList@@0x6D39AD05C873169B\n"
    "sceShellCoreUtilGetPbtcUserInfoList:\n");

asm(".global sceShellCoreUtilGetPlatformPrivacyDefinitionEventData\n"
    ".type   sceShellCoreUtilGetPlatformPrivacyDefinitionEventData, @function\n"
    ".symver sceShellCoreUtilGetPlatformPrivacyDefinitionEventData, sceShellCoreUtilGetPlatformPrivacyDefinitionEventData@@0x95794FFA384EF102\n"
    "sceShellCoreUtilGetPlatformPrivacyDefinitionEventData:\n");

asm(".global sceShellCoreUtilGetProgressOfFormatExternalHdd\n"
    ".type   sceShellCoreUtilGetProgressOfFormatExternalHdd, @function\n"
    ".symver sceShellCoreUtilGetProgressOfFormatExternalHdd, sceShellCoreUtilGetProgressOfFormatExternalHdd@@0x571589EC352B1084\n"
    "sceShellCoreUtilGetProgressOfFormatExternalHdd:\n");

asm(".global sceShellCoreUtilGetProgressOfFsck\n"
    ".type   sceShellCoreUtilGetProgressOfFsck, @function\n"
    ".symver sceShellCoreUtilGetProgressOfFsck, sceShellCoreUtilGetProgressOfFsck@@0xDCCD6D085F557E81\n"
    "sceShellCoreUtilGetProgressOfFsck:\n");

asm(".global sceShellCoreUtilGetPs4AppCategoryDefaultsListId\n"
    ".type   sceShellCoreUtilGetPs4AppCategoryDefaultsListId, @function\n"
    ".symver sceShellCoreUtilGetPs4AppCategoryDefaultsListId, sceShellCoreUtilGetPs4AppCategoryDefaultsListId@@0x09B5186CA80BB493\n"
    "sceShellCoreUtilGetPs4AppCategoryDefaultsListId:\n");

asm(".global sceShellCoreUtilGetPs4AppCategoryForTitleId\n"
    ".type   sceShellCoreUtilGetPs4AppCategoryForTitleId, @function\n"
    ".symver sceShellCoreUtilGetPs4AppCategoryForTitleId, sceShellCoreUtilGetPs4AppCategoryForTitleId@@0x1528AF1FD5CF7A1A\n"
    "sceShellCoreUtilGetPs4AppCategoryForTitleId:\n");

asm(".global sceShellCoreUtilGetPsStoreIconLayout\n"
    ".type   sceShellCoreUtilGetPsStoreIconLayout, @function\n"
    ".symver sceShellCoreUtilGetPsStoreIconLayout, sceShellCoreUtilGetPsStoreIconLayout@@0xD46DF19CC059A582\n"
    "sceShellCoreUtilGetPsStoreIconLayout:\n");

asm(".global sceShellCoreUtilGetPsStoreIconState\n"
    ".type   sceShellCoreUtilGetPsStoreIconState, @function\n"
    ".symver sceShellCoreUtilGetPsStoreIconState, sceShellCoreUtilGetPsStoreIconState@@0xCD2E993CB81025C0\n"
    "sceShellCoreUtilGetPsStoreIconState:\n");

asm(".global sceShellCoreUtilGetPsnAccountInfo\n"
    ".type   sceShellCoreUtilGetPsnAccountInfo, @function\n"
    ".symver sceShellCoreUtilGetPsnAccountInfo, sceShellCoreUtilGetPsnAccountInfo@@0xC7A4935E12041B43\n"
    "sceShellCoreUtilGetPsnAccountInfo:\n");

asm(".global sceShellCoreUtilGetRemotePlayStatus\n"
    ".type   sceShellCoreUtilGetRemotePlayStatus, @function\n"
    ".symver sceShellCoreUtilGetRemotePlayStatus, sceShellCoreUtilGetRemotePlayStatus@@0x6A2ECB70171FE91B\n"
    "sceShellCoreUtilGetRemotePlayStatus:\n");

asm(".global sceShellCoreUtilGetRunLevel\n"
    ".type   sceShellCoreUtilGetRunLevel, @function\n"
    ".symver sceShellCoreUtilGetRunLevel, sceShellCoreUtilGetRunLevel@@0x1DE6732F6C5B4496\n"
    "sceShellCoreUtilGetRunLevel:\n");

asm(".global sceShellCoreUtilGetSharePlayStatus\n"
    ".type   sceShellCoreUtilGetSharePlayStatus, @function\n"
    ".symver sceShellCoreUtilGetSharePlayStatus, sceShellCoreUtilGetSharePlayStatus@@0x2F99844A8F88ABE9\n"
    "sceShellCoreUtilGetSharePlayStatus:\n");

asm(".global sceShellCoreUtilGetSocialScreenStatus\n"
    ".type   sceShellCoreUtilGetSocialScreenStatus, @function\n"
    ".symver sceShellCoreUtilGetSocialScreenStatus, sceShellCoreUtilGetSocialScreenStatus@@0x9C6F87341C10E2CC\n"
    "sceShellCoreUtilGetSocialScreenStatus:\n");

asm(".global sceShellCoreUtilGetSplashScreenState\n"
    ".type   sceShellCoreUtilGetSplashScreenState, @function\n"
    ".symver sceShellCoreUtilGetSplashScreenState, sceShellCoreUtilGetSplashScreenState@@0x00587E8EE21AE213\n"
    "sceShellCoreUtilGetSplashScreenState:\n");

asm(".global sceShellCoreUtilGetSupportSiteURL\n"
    ".type   sceShellCoreUtilGetSupportSiteURL, @function\n"
    ".symver sceShellCoreUtilGetSupportSiteURL, sceShellCoreUtilGetSupportSiteURL@@0x3CF431884E256F26\n"
    "sceShellCoreUtilGetSupportSiteURL:\n");

asm(".global sceShellCoreUtilGetSuspendConfirmationDialogFlag\n"
    ".type   sceShellCoreUtilGetSuspendConfirmationDialogFlag, @function\n"
    ".symver sceShellCoreUtilGetSuspendConfirmationDialogFlag, sceShellCoreUtilGetSuspendConfirmationDialogFlag@@0xF62F91D6B8FA4EB9\n"
    "sceShellCoreUtilGetSuspendConfirmationDialogFlag:\n");

asm(".global sceShellCoreUtilGetSystemBGState\n"
    ".type   sceShellCoreUtilGetSystemBGState, @function\n"
    ".symver sceShellCoreUtilGetSystemBGState, sceShellCoreUtilGetSystemBGState@@0x58AC4E5489084B10\n"
    "sceShellCoreUtilGetSystemBGState:\n");

asm(".global sceShellCoreUtilGetSystemBGWaveColor\n"
    ".type   sceShellCoreUtilGetSystemBGWaveColor, @function\n"
    ".symver sceShellCoreUtilGetSystemBGWaveColor, sceShellCoreUtilGetSystemBGWaveColor@@0x5B91ED191099D621\n"
    "sceShellCoreUtilGetSystemBGWaveColor:\n");

asm(".global sceShellCoreUtilGetSystemBGWaveState\n"
    ".type   sceShellCoreUtilGetSystemBGWaveState, @function\n"
    ".symver sceShellCoreUtilGetSystemBGWaveState, sceShellCoreUtilGetSystemBGWaveState@@0x000FA4BD24723A03\n"
    "sceShellCoreUtilGetSystemBGWaveState:\n");

asm(".global sceShellCoreUtilGetTelemetryToken\n"
    ".type   sceShellCoreUtilGetTelemetryToken, @function\n"
    ".symver sceShellCoreUtilGetTelemetryToken, sceShellCoreUtilGetTelemetryToken@@0x00A138674C7C8A39\n"
    "sceShellCoreUtilGetTelemetryToken:\n");

asm(".global sceShellCoreUtilGetTitleWorkaroundFileInfoString\n"
    ".type   sceShellCoreUtilGetTitleWorkaroundFileInfoString, @function\n"
    ".symver sceShellCoreUtilGetTitleWorkaroundFileInfoString, sceShellCoreUtilGetTitleWorkaroundFileInfoString@@0x6466E47768568495\n"
    "sceShellCoreUtilGetTitleWorkaroundFileInfoString:\n");

asm(".global sceShellCoreUtilGetTitleWorkaroundFileString\n"
    ".type   sceShellCoreUtilGetTitleWorkaroundFileString, @function\n"
    ".symver sceShellCoreUtilGetTitleWorkaroundFileString, sceShellCoreUtilGetTitleWorkaroundFileString@@0xBEAF2E6C66F65E34\n"
    "sceShellCoreUtilGetTitleWorkaroundFileString:\n");

asm(".global sceShellCoreUtilGetUIStatus\n"
    ".type   sceShellCoreUtilGetUIStatus, @function\n"
    ".symver sceShellCoreUtilGetUIStatus, sceShellCoreUtilGetUIStatus@@0x7CE4599A58754D0A\n"
    "sceShellCoreUtilGetUIStatus:\n");

asm(".global sceShellCoreUtilGetUmmStatus\n"
    ".type   sceShellCoreUtilGetUmmStatus, @function\n"
    ".symver sceShellCoreUtilGetUmmStatus, sceShellCoreUtilGetUmmStatus@@0x07591E9778134528\n"
    "sceShellCoreUtilGetUmmStatus:\n");

asm(".global sceShellCoreUtilGetUserFocus\n"
    ".type   sceShellCoreUtilGetUserFocus, @function\n"
    ".symver sceShellCoreUtilGetUserFocus, sceShellCoreUtilGetUserFocus@@0x13823BB82A166E43\n"
    "sceShellCoreUtilGetUserFocus:\n");

asm(".global sceShellCoreUtilGetUserIdOfMorpheusUser\n"
    ".type   sceShellCoreUtilGetUserIdOfMorpheusUser, @function\n"
    ".symver sceShellCoreUtilGetUserIdOfMorpheusUser, sceShellCoreUtilGetUserIdOfMorpheusUser@@0xA652B9D8E7DE1087\n"
    "sceShellCoreUtilGetUserIdOfMorpheusUser:\n");

asm(".global sceShellCoreUtilGetVMStatsForTelemetry\n"
    ".type   sceShellCoreUtilGetVMStatsForTelemetry, @function\n"
    ".symver sceShellCoreUtilGetVMStatsForTelemetry, sceShellCoreUtilGetVMStatsForTelemetry@@0x112C6D2EF4193B96\n"
    "sceShellCoreUtilGetVMStatsForTelemetry:\n");

asm(".global sceShellCoreUtilGetVersionNumberOfCameraCalibrationData\n"
    ".type   sceShellCoreUtilGetVersionNumberOfCameraCalibrationData, @function\n"
    ".symver sceShellCoreUtilGetVersionNumberOfCameraCalibrationData, sceShellCoreUtilGetVersionNumberOfCameraCalibrationData@@0x55B1075BB46B27EC\n"
    "sceShellCoreUtilGetVersionNumberOfCameraCalibrationData:\n");

asm(".global sceShellCoreUtilGoBackToKratosCurrentSessionGame\n"
    ".type   sceShellCoreUtilGoBackToKratosCurrentSessionGame, @function\n"
    ".symver sceShellCoreUtilGoBackToKratosCurrentSessionGame, sceShellCoreUtilGoBackToKratosCurrentSessionGame@@0xD32D359DD9B4040F\n"
    "sceShellCoreUtilGoBackToKratosCurrentSessionGame:\n");

asm(".global sceShellCoreUtilHideBlocksFromUser\n"
    ".type   sceShellCoreUtilHideBlocksFromUser, @function\n"
    ".symver sceShellCoreUtilHideBlocksFromUser, sceShellCoreUtilHideBlocksFromUser@@0x00A21EBC1F884400\n"
    "sceShellCoreUtilHideBlocksFromUser:\n");

asm(".global sceShellCoreUtilIncrementVersionNumberOfCameraCalibrationData\n"
    ".type   sceShellCoreUtilIncrementVersionNumberOfCameraCalibrationData, @function\n"
    ".symver sceShellCoreUtilIncrementVersionNumberOfCameraCalibrationData, sceShellCoreUtilIncrementVersionNumberOfCameraCalibrationData@@0x000EF8B23C2249D6\n"
    "sceShellCoreUtilIncrementVersionNumberOfCameraCalibrationData:\n");

asm(".global sceShellCoreUtilIsAccessibilityZoomLocked\n"
    ".type   sceShellCoreUtilIsAccessibilityZoomLocked, @function\n"
    ".symver sceShellCoreUtilIsAccessibilityZoomLocked, sceShellCoreUtilIsAccessibilityZoomLocked@@0x00D9B6F9028B8BBF\n"
    "sceShellCoreUtilIsAccessibilityZoomLocked:\n");

asm(".global sceShellCoreUtilIsBgmCpuBudgetAcquired\n"
    ".type   sceShellCoreUtilIsBgmCpuBudgetAcquired, @function\n"
    ".symver sceShellCoreUtilIsBgmCpuBudgetAcquired, sceShellCoreUtilIsBgmCpuBudgetAcquired@@0xB28ABB1936D5324C\n"
    "sceShellCoreUtilIsBgmCpuBudgetAcquired:\n");

asm(".global sceShellCoreUtilIsBgmCpuBudgetAvailable\n"
    ".type   sceShellCoreUtilIsBgmCpuBudgetAvailable, @function\n"
    ".symver sceShellCoreUtilIsBgmCpuBudgetAvailable, sceShellCoreUtilIsBgmCpuBudgetAvailable@@0xBD81C9B59CA18442\n"
    "sceShellCoreUtilIsBgmCpuBudgetAvailable:\n");

asm(".global sceShellCoreUtilIsBgmPlaying\n"
    ".type   sceShellCoreUtilIsBgmPlaying, @function\n"
    ".symver sceShellCoreUtilIsBgmPlaying, sceShellCoreUtilIsBgmPlaying@@0x002E9AF980790791\n"
    "sceShellCoreUtilIsBgmPlaying:\n");

asm(".global sceShellCoreUtilIsExternalStorageAppMoveInProgress\n"
    ".type   sceShellCoreUtilIsExternalStorageAppMoveInProgress, @function\n"
    ".symver sceShellCoreUtilIsExternalStorageAppMoveInProgress, sceShellCoreUtilIsExternalStorageAppMoveInProgress@@0x9A978630BEEE940F\n"
    "sceShellCoreUtilIsExternalStorageAppMoveInProgress:\n");

asm(".global sceShellCoreUtilIsEyeToEyeDistanceAdjusted\n"
    ".type   sceShellCoreUtilIsEyeToEyeDistanceAdjusted, @function\n"
    ".symver sceShellCoreUtilIsEyeToEyeDistanceAdjusted, sceShellCoreUtilIsEyeToEyeDistanceAdjusted@@0x3C6B001A79D1B2D6\n"
    "sceShellCoreUtilIsEyeToEyeDistanceAdjusted:\n");

asm(".global sceShellCoreUtilIsGameLiveStreamingOnAir\n"
    ".type   sceShellCoreUtilIsGameLiveStreamingOnAir, @function\n"
    ".symver sceShellCoreUtilIsGameLiveStreamingOnAir, sceShellCoreUtilIsGameLiveStreamingOnAir@@0x2B2418D8A7CCC4AC\n"
    "sceShellCoreUtilIsGameLiveStreamingOnAir:\n");

asm(".global sceShellCoreUtilIsIDUState\n"
    ".type   sceShellCoreUtilIsIDUState, @function\n"
    ".symver sceShellCoreUtilIsIDUState, sceShellCoreUtilIsIDUState@@0x7C18D8D6563BB1BB\n"
    "sceShellCoreUtilIsIDUState:\n");

asm(".global sceShellCoreUtilIsImposeScreenOverlaid\n"
    ".type   sceShellCoreUtilIsImposeScreenOverlaid, @function\n"
    ".symver sceShellCoreUtilIsImposeScreenOverlaid, sceShellCoreUtilIsImposeScreenOverlaid@@0x8B3A3706B9966433\n"
    "sceShellCoreUtilIsImposeScreenOverlaid:\n");

asm(".global sceShellCoreUtilIsInSystemSuspendBlackList\n"
    ".type   sceShellCoreUtilIsInSystemSuspendBlackList, @function\n"
    ".symver sceShellCoreUtilIsInSystemSuspendBlackList, sceShellCoreUtilIsInSystemSuspendBlackList@@0xC026C6DF756C6EA4\n"
    "sceShellCoreUtilIsInSystemSuspendBlackList:\n");

asm(".global sceShellCoreUtilIsInternalKratosUser\n"
    ".type   sceShellCoreUtilIsInternalKratosUser, @function\n"
    ".symver sceShellCoreUtilIsInternalKratosUser, sceShellCoreUtilIsInternalKratosUser@@0x993671542DE979B7\n"
    "sceShellCoreUtilIsInternalKratosUser:\n");

asm(".global sceShellCoreUtilIsKilledOrSuspendedByLogout\n"
    ".type   sceShellCoreUtilIsKilledOrSuspendedByLogout, @function\n"
    ".symver sceShellCoreUtilIsKilledOrSuspendedByLogout, sceShellCoreUtilIsKilledOrSuspendedByLogout@@0xE383C25604C1042C\n"
    "sceShellCoreUtilIsKilledOrSuspendedByLogout:\n");

asm(".global sceShellCoreUtilIsNeededCrashReport\n"
    ".type   sceShellCoreUtilIsNeededCrashReport, @function\n"
    ".symver sceShellCoreUtilIsNeededCrashReport, sceShellCoreUtilIsNeededCrashReport@@0x287D089C0D2E4AD8\n"
    "sceShellCoreUtilIsNeededCrashReport:\n");

asm(".global sceShellCoreUtilIsPowerSaveAlertRequested\n"
    ".type   sceShellCoreUtilIsPowerSaveAlertRequested, @function\n"
    ".symver sceShellCoreUtilIsPowerSaveAlertRequested, sceShellCoreUtilIsPowerSaveAlertRequested@@0xDC9347CEB1039EB9\n"
    "sceShellCoreUtilIsPowerSaveAlertRequested:\n");

asm(".global sceShellCoreUtilIsRemotePlayCpuBudgetAcquired\n"
    ".type   sceShellCoreUtilIsRemotePlayCpuBudgetAcquired, @function\n"
    ".symver sceShellCoreUtilIsRemotePlayCpuBudgetAcquired, sceShellCoreUtilIsRemotePlayCpuBudgetAcquired@@0x0967318D3E97FB57\n"
    "sceShellCoreUtilIsRemotePlayCpuBudgetAcquired:\n");

asm(".global sceShellCoreUtilIsScreenSaverOn\n"
    ".type   sceShellCoreUtilIsScreenSaverOn, @function\n"
    ".symver sceShellCoreUtilIsScreenSaverOn, sceShellCoreUtilIsScreenSaverOn@@0x58811427AD40C2F5\n"
    "sceShellCoreUtilIsScreenSaverOn:\n");

asm(".global sceShellCoreUtilIsSharePlayCpuBudgetAcquired\n"
    ".type   sceShellCoreUtilIsSharePlayCpuBudgetAcquired, @function\n"
    ".symver sceShellCoreUtilIsSharePlayCpuBudgetAcquired, sceShellCoreUtilIsSharePlayCpuBudgetAcquired@@0x81632516AE0DF4BC\n"
    "sceShellCoreUtilIsSharePlayCpuBudgetAcquired:\n");

asm(".global sceShellCoreUtilIsShowCrashReport\n"
    ".type   sceShellCoreUtilIsShowCrashReport, @function\n"
    ".symver sceShellCoreUtilIsShowCrashReport, sceShellCoreUtilIsShowCrashReport@@0x18467DB08CF7C2E3\n"
    "sceShellCoreUtilIsShowCrashReport:\n");

asm(".global sceShellCoreUtilIsTemperatureDanger\n"
    ".type   sceShellCoreUtilIsTemperatureDanger, @function\n"
    ".symver sceShellCoreUtilIsTemperatureDanger, sceShellCoreUtilIsTemperatureDanger@@0xBF35A87ADC9A52E0\n"
    "sceShellCoreUtilIsTemperatureDanger:\n");

asm(".global sceShellCoreUtilIsTitleWorkaroundEnabled\n"
    ".type   sceShellCoreUtilIsTitleWorkaroundEnabled, @function\n"
    ".symver sceShellCoreUtilIsTitleWorkaroundEnabled, sceShellCoreUtilIsTitleWorkaroundEnabled@@0xE1DB0D3F054E0CA3\n"
    "sceShellCoreUtilIsTitleWorkaroundEnabled:\n");

asm(".global sceShellCoreUtilIsUsbMassStorageMounted\n"
    ".type   sceShellCoreUtilIsUsbMassStorageMounted, @function\n"
    ".symver sceShellCoreUtilIsUsbMassStorageMounted, sceShellCoreUtilIsUsbMassStorageMounted@@0x2071D2755053C017\n"
    "sceShellCoreUtilIsUsbMassStorageMounted:\n");

asm(".global sceShellCoreUtilLaunchByUri\n"
    ".type   sceShellCoreUtilLaunchByUri, @function\n"
    ".symver sceShellCoreUtilLaunchByUri, sceShellCoreUtilLaunchByUri@@0x198524E2DDBB332C\n"
    "sceShellCoreUtilLaunchByUri:\n");

asm(".global sceShellCoreUtilLeavePowerLockSection\n"
    ".type   sceShellCoreUtilLeavePowerLockSection, @function\n"
    ".symver sceShellCoreUtilLeavePowerLockSection, sceShellCoreUtilLeavePowerLockSection@@0x9C436F500B0029D6\n"
    "sceShellCoreUtilLeavePowerLockSection:\n");

asm(".global sceShellCoreUtilMakeManifestFile\n"
    ".type   sceShellCoreUtilMakeManifestFile, @function\n"
    ".symver sceShellCoreUtilMakeManifestFile, sceShellCoreUtilMakeManifestFile@@0x004A9D5A6AA23549\n"
    "sceShellCoreUtilMakeManifestFile:\n");

asm(".global sceShellCoreUtilMountAppRight\n"
    ".type   sceShellCoreUtilMountAppRight, @function\n"
    ".symver sceShellCoreUtilMountAppRight, sceShellCoreUtilMountAppRight@@0x68290CF8E686BF78\n"
    "sceShellCoreUtilMountAppRight:\n");

asm(".global sceShellCoreUtilMountDownloadDataForShellUI\n"
    ".type   sceShellCoreUtilMountDownloadDataForShellUI, @function\n"
    ".symver sceShellCoreUtilMountDownloadDataForShellUI, sceShellCoreUtilMountDownloadDataForShellUI@@0x8EEAA53D95A42467\n"
    "sceShellCoreUtilMountDownloadDataForShellUI:\n");

asm(".global sceShellCoreUtilMountHddForBackup\n"
    ".type   sceShellCoreUtilMountHddForBackup, @function\n"
    ".symver sceShellCoreUtilMountHddForBackup, sceShellCoreUtilMountHddForBackup@@0xA8D7BCB8D7B71294\n"
    "sceShellCoreUtilMountHddForBackup:\n");

asm(".global sceShellCoreUtilMountHddForRestore\n"
    ".type   sceShellCoreUtilMountHddForRestore, @function\n"
    ".symver sceShellCoreUtilMountHddForRestore, sceShellCoreUtilMountHddForRestore@@0x6D108BC38F4DE211\n"
    "sceShellCoreUtilMountHddForRestore:\n");

asm(".global sceShellCoreUtilNavigateToAnotherApp\n"
    ".type   sceShellCoreUtilNavigateToAnotherApp, @function\n"
    ".symver sceShellCoreUtilNavigateToAnotherApp, sceShellCoreUtilNavigateToAnotherApp@@0xD5EEC2985949BDE5\n"
    "sceShellCoreUtilNavigateToAnotherApp:\n");

asm(".global sceShellCoreUtilNavigateToGoHome\n"
    ".type   sceShellCoreUtilNavigateToGoHome, @function\n"
    ".symver sceShellCoreUtilNavigateToGoHome, sceShellCoreUtilNavigateToGoHome@@0x9FDC5140FB543F48\n"
    "sceShellCoreUtilNavigateToGoHome:\n");

asm(".global sceShellCoreUtilNavigateToLaunchedApp\n"
    ".type   sceShellCoreUtilNavigateToLaunchedApp, @function\n"
    ".symver sceShellCoreUtilNavigateToLaunchedApp, sceShellCoreUtilNavigateToLaunchedApp@@0x00322F42C1EBE252\n"
    "sceShellCoreUtilNavigateToLaunchedApp:\n");

asm(".global sceShellCoreUtilNotificationCancelForIDU\n"
    ".type   sceShellCoreUtilNotificationCancelForIDU, @function\n"
    ".symver sceShellCoreUtilNotificationCancelForIDU, sceShellCoreUtilNotificationCancelForIDU@@0x00579723B3EF6423\n"
    "sceShellCoreUtilNotificationCancelForIDU:\n");

asm(".global sceShellCoreUtilNotificationRequestedForIDU\n"
    ".type   sceShellCoreUtilNotificationRequestedForIDU, @function\n"
    ".symver sceShellCoreUtilNotificationRequestedForIDU, sceShellCoreUtilNotificationRequestedForIDU@@0x5504563B16066B2B\n"
    "sceShellCoreUtilNotificationRequestedForIDU:\n");

asm(".global sceShellCoreUtilNotifyBgmCoreTermination\n"
    ".type   sceShellCoreUtilNotifyBgmCoreTermination, @function\n"
    ".symver sceShellCoreUtilNotifyBgmCoreTermination, sceShellCoreUtilNotifyBgmCoreTermination@@0xAE8510C026187A01\n"
    "sceShellCoreUtilNotifyBgmCoreTermination:\n");

asm(".global sceShellCoreUtilNotifyFsReadError\n"
    ".type   sceShellCoreUtilNotifyFsReadError, @function\n"
    ".symver sceShellCoreUtilNotifyFsReadError, sceShellCoreUtilNotifyFsReadError@@0x6B00539B4BCD6A8B\n"
    "sceShellCoreUtilNotifyFsReadError:\n");

asm(".global sceShellCoreUtilNotifyImeStatusChanged\n"
    ".type   sceShellCoreUtilNotifyImeStatusChanged, @function\n"
    ".symver sceShellCoreUtilNotifyImeStatusChanged, sceShellCoreUtilNotifyImeStatusChanged@@0xD63C00B403FB2B25\n"
    "sceShellCoreUtilNotifyImeStatusChanged:\n");

asm(".global sceShellCoreUtilNotifyPsnAccountInfoReceived\n"
    ".type   sceShellCoreUtilNotifyPsnAccountInfoReceived, @function\n"
    ".symver sceShellCoreUtilNotifyPsnAccountInfoReceived, sceShellCoreUtilNotifyPsnAccountInfoReceived@@0x007643C8C56329F2\n"
    "sceShellCoreUtilNotifyPsnAccountInfoReceived:\n");

asm(".global sceShellCoreUtilNotifySystemSuspendTelemetryInfo\n"
    ".type   sceShellCoreUtilNotifySystemSuspendTelemetryInfo, @function\n"
    ".symver sceShellCoreUtilNotifySystemSuspendTelemetryInfo, sceShellCoreUtilNotifySystemSuspendTelemetryInfo@@0xBDB12A81E6046C14\n"
    "sceShellCoreUtilNotifySystemSuspendTelemetryInfo:\n");

asm(".global sceShellCoreUtilPfAuthClientConsoleTokenClearCache\n"
    ".type   sceShellCoreUtilPfAuthClientConsoleTokenClearCache, @function\n"
    ".symver sceShellCoreUtilPfAuthClientConsoleTokenClearCache, sceShellCoreUtilPfAuthClientConsoleTokenClearCache@@0x4E0B39CCE51F4127\n"
    "sceShellCoreUtilPfAuthClientConsoleTokenClearCache:\n");

asm(".global sceShellCoreUtilPostActivityForPsNow\n"
    ".type   sceShellCoreUtilPostActivityForPsNow, @function\n"
    ".symver sceShellCoreUtilPostActivityForPsNow, sceShellCoreUtilPostActivityForPsNow@@0xA5BD973CC5796DE2\n"
    "sceShellCoreUtilPostActivityForPsNow:\n");

asm(".global sceShellCoreUtilPostErrorLog\n"
    ".type   sceShellCoreUtilPostErrorLog, @function\n"
    ".symver sceShellCoreUtilPostErrorLog, sceShellCoreUtilPostErrorLog@@0x0086B31776966E0D\n"
    "sceShellCoreUtilPostErrorLog:\n");

asm(".global sceShellCoreUtilPostLaunchConfirmResult\n"
    ".type   sceShellCoreUtilPostLaunchConfirmResult, @function\n"
    ".symver sceShellCoreUtilPostLaunchConfirmResult, sceShellCoreUtilPostLaunchConfirmResult@@0x007C2792168D0833\n"
    "sceShellCoreUtilPostLaunchConfirmResult:\n");

asm(".global sceShellCoreUtilPostPsmEventToShellUI\n"
    ".type   sceShellCoreUtilPostPsmEventToShellUI, @function\n"
    ".symver sceShellCoreUtilPostPsmEventToShellUI, sceShellCoreUtilPostPsmEventToShellUI@@0x7190894CC6A60CE1\n"
    "sceShellCoreUtilPostPsmEventToShellUI:\n");

asm(".global sceShellCoreUtilPreNotifyOfGameLiveStreaming\n"
    ".type   sceShellCoreUtilPreNotifyOfGameLiveStreaming, @function\n"
    ".symver sceShellCoreUtilPreNotifyOfGameLiveStreaming, sceShellCoreUtilPreNotifyOfGameLiveStreaming@@0x3C61E38ED6712AFB\n"
    "sceShellCoreUtilPreNotifyOfGameLiveStreaming:\n");

asm(".global sceShellCoreUtilPreNotifyOfRemotePlay\n"
    ".type   sceShellCoreUtilPreNotifyOfRemotePlay, @function\n"
    ".symver sceShellCoreUtilPreNotifyOfRemotePlay, sceShellCoreUtilPreNotifyOfRemotePlay@@0x0029016F0D76126E\n"
    "sceShellCoreUtilPreNotifyOfRemotePlay:\n");

asm(".global sceShellCoreUtilPreNotifyOfSharePlay\n"
    ".type   sceShellCoreUtilPreNotifyOfSharePlay, @function\n"
    ".symver sceShellCoreUtilPreNotifyOfSharePlay, sceShellCoreUtilPreNotifyOfSharePlay@@0x001C102D0965173F\n"
    "sceShellCoreUtilPreNotifyOfSharePlay:\n");

asm(".global sceShellCoreUtilReleaseBgmCpuBudget\n"
    ".type   sceShellCoreUtilReleaseBgmCpuBudget, @function\n"
    ".symver sceShellCoreUtilReleaseBgmCpuBudget, sceShellCoreUtilReleaseBgmCpuBudget@@0x10584CF521766924\n"
    "sceShellCoreUtilReleaseBgmCpuBudget:\n");

asm(".global sceShellCoreUtilReleaseRemotePlayCpuBudget\n"
    ".type   sceShellCoreUtilReleaseRemotePlayCpuBudget, @function\n"
    ".symver sceShellCoreUtilReleaseRemotePlayCpuBudget, sceShellCoreUtilReleaseRemotePlayCpuBudget@@0x71F2594E14D2C50D\n"
    "sceShellCoreUtilReleaseRemotePlayCpuBudget:\n");

asm(".global sceShellCoreUtilReleaseSharePlayCpuBudget\n"
    ".type   sceShellCoreUtilReleaseSharePlayCpuBudget, @function\n"
    ".symver sceShellCoreUtilReleaseSharePlayCpuBudget, sceShellCoreUtilReleaseSharePlayCpuBudget@@0x8CA9F039D81C9398\n"
    "sceShellCoreUtilReleaseSharePlayCpuBudget:\n");

asm(".global sceShellCoreUtilReportSessionErrorToGaikaiController\n"
    ".type   sceShellCoreUtilReportSessionErrorToGaikaiController, @function\n"
    ".symver sceShellCoreUtilReportSessionErrorToGaikaiController, sceShellCoreUtilReportSessionErrorToGaikaiController@@0x00C8E7A4679B6869\n"
    "sceShellCoreUtilReportSessionErrorToGaikaiController:\n");

asm(".global sceShellCoreUtilReportUnexpectedFatalErrorToSystemTelemetry\n"
    ".type   sceShellCoreUtilReportUnexpectedFatalErrorToSystemTelemetry, @function\n"
    ".symver sceShellCoreUtilReportUnexpectedFatalErrorToSystemTelemetry, sceShellCoreUtilReportUnexpectedFatalErrorToSystemTelemetry@@0x945F7A4ABF097F4B\n"
    "sceShellCoreUtilReportUnexpectedFatalErrorToSystemTelemetry:\n");

asm(".global sceShellCoreUtilRequestCameraCalibration\n"
    ".type   sceShellCoreUtilRequestCameraCalibration, @function\n"
    ".symver sceShellCoreUtilRequestCameraCalibration, sceShellCoreUtilRequestCameraCalibration@@0x00C983C96F47A33B\n"
    "sceShellCoreUtilRequestCameraCalibration:\n");

asm(".global sceShellCoreUtilRequestEjectDevice\n"
    ".type   sceShellCoreUtilRequestEjectDevice, @function\n"
    ".symver sceShellCoreUtilRequestEjectDevice, sceShellCoreUtilRequestEjectDevice@@0xF3E0A695076AEEEF\n"
    "sceShellCoreUtilRequestEjectDevice:\n");

asm(".global sceShellCoreUtilRequestRebootApp\n"
    ".type   sceShellCoreUtilRequestRebootApp, @function\n"
    ".symver sceShellCoreUtilRequestRebootApp, sceShellCoreUtilRequestRebootApp@@0xFB6A5A02C2AA5CE4\n"
    "sceShellCoreUtilRequestRebootApp:\n");

asm(".global sceShellCoreUtilRequestShutdown\n"
    ".type   sceShellCoreUtilRequestShutdown, @function\n"
    ".symver sceShellCoreUtilRequestShutdown, sceShellCoreUtilRequestShutdown@@0xEC9812267681C88B\n"
    "sceShellCoreUtilRequestShutdown:\n");

asm(".global sceShellCoreUtilResetAutoPowerDownTimer\n"
    ".type   sceShellCoreUtilResetAutoPowerDownTimer, @function\n"
    ".symver sceShellCoreUtilResetAutoPowerDownTimer, sceShellCoreUtilResetAutoPowerDownTimer@@0x23340DF85E6ADF08\n"
    "sceShellCoreUtilResetAutoPowerDownTimer:\n");

asm(".global sceShellCoreUtilResetBgdcConfig\n"
    ".type   sceShellCoreUtilResetBgdcConfig, @function\n"
    ".symver sceShellCoreUtilResetBgdcConfig, sceShellCoreUtilResetBgdcConfig@@0xEF25109995A8A958\n"
    "sceShellCoreUtilResetBgdcConfig:\n");

asm(".global sceShellCoreUtilSetAppData\n"
    ".type   sceShellCoreUtilSetAppData, @function\n"
    ".symver sceShellCoreUtilSetAppData, sceShellCoreUtilSetAppData@@0xC4A4A0692557D62A\n"
    "sceShellCoreUtilSetAppData:\n");

asm(".global sceShellCoreUtilSetBgmProhibition\n"
    ".type   sceShellCoreUtilSetBgmProhibition, @function\n"
    ".symver sceShellCoreUtilSetBgmProhibition, sceShellCoreUtilSetBgmProhibition@@0x752D7ED43D4B447B\n"
    "sceShellCoreUtilSetBgmProhibition:\n");

asm(".global sceShellCoreUtilSetDeviceIndexBehavior\n"
    ".type   sceShellCoreUtilSetDeviceIndexBehavior, @function\n"
    ".symver sceShellCoreUtilSetDeviceIndexBehavior, sceShellCoreUtilSetDeviceIndexBehavior@@0x97DE9895412D30F9\n"
    "sceShellCoreUtilSetDeviceIndexBehavior:\n");

asm(".global sceShellCoreUtilSetGameLiveStreamingOnAirFlag\n"
    ".type   sceShellCoreUtilSetGameLiveStreamingOnAirFlag, @function\n"
    ".symver sceShellCoreUtilSetGameLiveStreamingOnAirFlag, sceShellCoreUtilSetGameLiveStreamingOnAirFlag@@0x6C2F2FA3AD3C3F61\n"
    "sceShellCoreUtilSetGameLiveStreamingOnAirFlag:\n");

asm(".global sceShellCoreUtilSetGameLiveStreamingStatus\n"
    ".type   sceShellCoreUtilSetGameLiveStreamingStatus, @function\n"
    ".symver sceShellCoreUtilSetGameLiveStreamingStatus, sceShellCoreUtilSetGameLiveStreamingStatus@@0x2B7DFE1308AD5A5A\n"
    "sceShellCoreUtilSetGameLiveStreamingStatus:\n");

asm(".global sceShellCoreUtilSetGnmCompositorOnScreenProfilerFlag\n"
    ".type   sceShellCoreUtilSetGnmCompositorOnScreenProfilerFlag, @function\n"
    ".symver sceShellCoreUtilSetGnmCompositorOnScreenProfilerFlag, sceShellCoreUtilSetGnmCompositorOnScreenProfilerFlag@@0x9BAE6E2AFEC80242\n"
    "sceShellCoreUtilSetGnmCompositorOnScreenProfilerFlag:\n");

asm(".global sceShellCoreUtilSetGpuLoadEmulationMode\n"
    ".type   sceShellCoreUtilSetGpuLoadEmulationMode, @function\n"
    ".symver sceShellCoreUtilSetGpuLoadEmulationMode, sceShellCoreUtilSetGpuLoadEmulationMode@@0x31E6E88A85689A7B\n"
    "sceShellCoreUtilSetGpuLoadEmulationMode:\n");

asm(".global sceShellCoreUtilSetGpuLoadEmulationModeByAppId\n"
    ".type   sceShellCoreUtilSetGpuLoadEmulationModeByAppId, @function\n"
    ".symver sceShellCoreUtilSetGpuLoadEmulationModeByAppId, sceShellCoreUtilSetGpuLoadEmulationModeByAppId@@0xCDDE285575860F66\n"
    "sceShellCoreUtilSetGpuLoadEmulationModeByAppId:\n");

asm(".global sceShellCoreUtilSetIDUMode\n"
    ".type   sceShellCoreUtilSetIDUMode, @function\n"
    ".symver sceShellCoreUtilSetIDUMode, sceShellCoreUtilSetIDUMode@@0x00E0F77482518433\n"
    "sceShellCoreUtilSetIDUMode:\n");

asm(".global sceShellCoreUtilSetImposeStatusFlag\n"
    ".type   sceShellCoreUtilSetImposeStatusFlag, @function\n"
    ".symver sceShellCoreUtilSetImposeStatusFlag, sceShellCoreUtilSetImposeStatusFlag@@0x4C9A7791D486B08C\n"
    "sceShellCoreUtilSetImposeStatusFlag:\n");

asm(".global sceShellCoreUtilSetPsStoreIconLayout\n"
    ".type   sceShellCoreUtilSetPsStoreIconLayout, @function\n"
    ".symver sceShellCoreUtilSetPsStoreIconLayout, sceShellCoreUtilSetPsStoreIconLayout@@0xAAD8E3A2B5B557DE\n"
    "sceShellCoreUtilSetPsStoreIconLayout:\n");

asm(".global sceShellCoreUtilSetPsStoreIconState\n"
    ".type   sceShellCoreUtilSetPsStoreIconState, @function\n"
    ".symver sceShellCoreUtilSetPsStoreIconState, sceShellCoreUtilSetPsStoreIconState@@0x83BF3BB4C040D531\n"
    "sceShellCoreUtilSetPsStoreIconState:\n");

asm(".global sceShellCoreUtilSetRemotePlayStatus\n"
    ".type   sceShellCoreUtilSetRemotePlayStatus, @function\n"
    ".symver sceShellCoreUtilSetRemotePlayStatus, sceShellCoreUtilSetRemotePlayStatus@@0x8EA8F9BDB8256D95\n"
    "sceShellCoreUtilSetRemotePlayStatus:\n");

asm(".global sceShellCoreUtilSetSharePlayStatus\n"
    ".type   sceShellCoreUtilSetSharePlayStatus, @function\n"
    ".symver sceShellCoreUtilSetSharePlayStatus, sceShellCoreUtilSetSharePlayStatus@@0x976D930086DBB45C\n"
    "sceShellCoreUtilSetSharePlayStatus:\n");

asm(".global sceShellCoreUtilSetSkipUpdateCheck\n"
    ".type   sceShellCoreUtilSetSkipUpdateCheck, @function\n"
    ".symver sceShellCoreUtilSetSkipUpdateCheck, sceShellCoreUtilSetSkipUpdateCheck@@0x2164823B6D11C086\n"
    "sceShellCoreUtilSetSkipUpdateCheck:\n");

asm(".global sceShellCoreUtilSetSocialScreenStatus\n"
    ".type   sceShellCoreUtilSetSocialScreenStatus, @function\n"
    ".symver sceShellCoreUtilSetSocialScreenStatus, sceShellCoreUtilSetSocialScreenStatus@@0x9C0E6B4702EB8085\n"
    "sceShellCoreUtilSetSocialScreenStatus:\n");

asm(".global sceShellCoreUtilSetSplashScreenState\n"
    ".type   sceShellCoreUtilSetSplashScreenState, @function\n"
    ".symver sceShellCoreUtilSetSplashScreenState, sceShellCoreUtilSetSplashScreenState@@0x00D8F9ACEE208416\n"
    "sceShellCoreUtilSetSplashScreenState:\n");

asm(".global sceShellCoreUtilSetSystemBGState\n"
    ".type   sceShellCoreUtilSetSystemBGState, @function\n"
    ".symver sceShellCoreUtilSetSystemBGState, sceShellCoreUtilSetSystemBGState@@0x91FCAE1250049E2B\n"
    "sceShellCoreUtilSetSystemBGState:\n");

asm(".global sceShellCoreUtilSetSystemBGWaveColor\n"
    ".type   sceShellCoreUtilSetSystemBGWaveColor, @function\n"
    ".symver sceShellCoreUtilSetSystemBGWaveColor, sceShellCoreUtilSetSystemBGWaveColor@@0x00523CF6E495E33C\n"
    "sceShellCoreUtilSetSystemBGWaveColor:\n");

asm(".global sceShellCoreUtilSetSystemBGWaveState\n"
    ".type   sceShellCoreUtilSetSystemBGWaveState, @function\n"
    ".symver sceShellCoreUtilSetSystemBGWaveState, sceShellCoreUtilSetSystemBGWaveState@@0x00181D7D71F4538A\n"
    "sceShellCoreUtilSetSystemBGWaveState:\n");

asm(".global sceShellCoreUtilSetUIStatus\n"
    ".type   sceShellCoreUtilSetUIStatus, @function\n"
    ".symver sceShellCoreUtilSetUIStatus, sceShellCoreUtilSetUIStatus@@0x6AD8944EC4C52779\n"
    "sceShellCoreUtilSetUIStatus:\n");

asm(".global sceShellCoreUtilSetUserFocus\n"
    ".type   sceShellCoreUtilSetUserFocus, @function\n"
    ".symver sceShellCoreUtilSetUserFocus, sceShellCoreUtilSetUserFocus@@0x00F5D8D68F5354E0\n"
    "sceShellCoreUtilSetUserFocus:\n");

asm(".global sceShellCoreUtilShowCriticalErrorDialog\n"
    ".type   sceShellCoreUtilShowCriticalErrorDialog, @function\n"
    ".symver sceShellCoreUtilShowCriticalErrorDialog, sceShellCoreUtilShowCriticalErrorDialog@@0x956FBCA5D4D03268\n"
    "sceShellCoreUtilShowCriticalErrorDialog:\n");

asm(".global sceShellCoreUtilShowErrorDialog\n"
    ".type   sceShellCoreUtilShowErrorDialog, @function\n"
    ".symver sceShellCoreUtilShowErrorDialog, sceShellCoreUtilShowErrorDialog@@0xD29B598AED23049B\n"
    "sceShellCoreUtilShowErrorDialog:\n");

asm(".global sceShellCoreUtilShowErrorDialogWithFormatArgs\n"
    ".type   sceShellCoreUtilShowErrorDialogWithFormatArgs, @function\n"
    ".symver sceShellCoreUtilShowErrorDialogWithFormatArgs, sceShellCoreUtilShowErrorDialogWithFormatArgs@@0x7216451E719AF71E\n"
    "sceShellCoreUtilShowErrorDialogWithFormatArgs:\n");

asm(".global sceShellCoreUtilShowErrorDialogWithParam\n"
    ".type   sceShellCoreUtilShowErrorDialogWithParam, @function\n"
    ".symver sceShellCoreUtilShowErrorDialogWithParam, sceShellCoreUtilShowErrorDialogWithParam@@0xCB189450F268C982\n"
    "sceShellCoreUtilShowErrorDialogWithParam:\n");

asm(".global sceShellCoreUtilShowPsUnderLockIndicator\n"
    ".type   sceShellCoreUtilShowPsUnderLockIndicator, @function\n"
    ".symver sceShellCoreUtilShowPsUnderLockIndicator, sceShellCoreUtilShowPsUnderLockIndicator@@0x1A33B18C85590356\n"
    "sceShellCoreUtilShowPsUnderLockIndicator:\n");

asm(".global sceShellCoreUtilSignalUserInput\n"
    ".type   sceShellCoreUtilSignalUserInput, @function\n"
    ".symver sceShellCoreUtilSignalUserInput, sceShellCoreUtilSignalUserInput@@0x474D770F55481134\n"
    "sceShellCoreUtilSignalUserInput:\n");

asm(".global sceShellCoreUtilStartPsNowGame\n"
    ".type   sceShellCoreUtilStartPsNowGame, @function\n"
    ".symver sceShellCoreUtilStartPsNowGame, sceShellCoreUtilStartPsNowGame@@0x0000000000000000\n"
    "sceShellCoreUtilStartPsNowGame:\n");

asm(".global sceShellCoreUtilStopPsNowGame\n"
    ".type   sceShellCoreUtilStopPsNowGame, @function\n"
    ".symver sceShellCoreUtilStopPsNowGame, sceShellCoreUtilStopPsNowGame@@0xF5DBD506E92A3ACC\n"
    "sceShellCoreUtilStopPsNowGame:\n");

asm(".global sceShellCoreUtilTalkKeyEventReceived\n"
    ".type   sceShellCoreUtilTalkKeyEventReceived, @function\n"
    ".symver sceShellCoreUtilTalkKeyEventReceived, sceShellCoreUtilTalkKeyEventReceived@@0xD09B92DF39035DD7\n"
    "sceShellCoreUtilTalkKeyEventReceived:\n");

asm(".global sceShellCoreUtilTestBusTransferSpeed\n"
    ".type   sceShellCoreUtilTestBusTransferSpeed, @function\n"
    ".symver sceShellCoreUtilTestBusTransferSpeed, sceShellCoreUtilTestBusTransferSpeed@@0x75BC32CC02E528E4\n"
    "sceShellCoreUtilTestBusTransferSpeed:\n");

asm(".global sceShellCoreUtilTickHeartBeat\n"
    ".type   sceShellCoreUtilTickHeartBeat, @function\n"
    ".symver sceShellCoreUtilTickHeartBeat, sceShellCoreUtilTickHeartBeat@@0x0D656FD0C944D6CC\n"
    "sceShellCoreUtilTickHeartBeat:\n");

asm(".global sceShellCoreUtilTriggerPapcUpdate\n"
    ".type   sceShellCoreUtilTriggerPapcUpdate, @function\n"
    ".symver sceShellCoreUtilTriggerPapcUpdate, sceShellCoreUtilTriggerPapcUpdate@@0x0929753007546D8B\n"
    "sceShellCoreUtilTriggerPapcUpdate:\n");

asm(".global sceShellCoreUtilTurnOffScreenSaver\n"
    ".type   sceShellCoreUtilTurnOffScreenSaver, @function\n"
    ".symver sceShellCoreUtilTurnOffScreenSaver, sceShellCoreUtilTurnOffScreenSaver@@0x95CA7D13BEC3001E\n"
    "sceShellCoreUtilTurnOffScreenSaver:\n");

asm(".global sceShellCoreUtilUnmountAppRight\n"
    ".type   sceShellCoreUtilUnmountAppRight, @function\n"
    ".symver sceShellCoreUtilUnmountAppRight, sceShellCoreUtilUnmountAppRight@@0x4FDC5E89F114177C\n"
    "sceShellCoreUtilUnmountAppRight:\n");

asm(".global sceShellCoreUtilUnmountDownloadDataForShellUI\n"
    ".type   sceShellCoreUtilUnmountDownloadDataForShellUI, @function\n"
    ".symver sceShellCoreUtilUnmountDownloadDataForShellUI, sceShellCoreUtilUnmountDownloadDataForShellUI@@0xAAA2F9558C052E0A\n"
    "sceShellCoreUtilUnmountDownloadDataForShellUI:\n");

asm(".global sceShellCoreUtilUnmountHddForBackup\n"
    ".type   sceShellCoreUtilUnmountHddForBackup, @function\n"
    ".symver sceShellCoreUtilUnmountHddForBackup, sceShellCoreUtilUnmountHddForBackup@@0x0062F0A3E1C6F58D\n"
    "sceShellCoreUtilUnmountHddForBackup:\n");

asm(".global sceShellCoreUtilUnmountHddForRestore\n"
    ".type   sceShellCoreUtilUnmountHddForRestore, @function\n"
    ".symver sceShellCoreUtilUnmountHddForRestore, sceShellCoreUtilUnmountHddForRestore@@0xA1EC8746DE4F3FE4\n"
    "sceShellCoreUtilUnmountHddForRestore:\n");

asm(".global sceShellCoreutilGetCrashReportProcessInformation\n"
    ".type   sceShellCoreutilGetCrashReportProcessInformation, @function\n"
    ".symver sceShellCoreutilGetCrashReportProcessInformation, sceShellCoreutilGetCrashReportProcessInformation@@0x00DFAF1EB33990B9\n"
    "sceShellCoreutilGetCrashReportProcessInformation:\n");

asm(".global sceSystemModalDialogClose\n"
    ".type   sceSystemModalDialogClose, @function\n"
    ".symver sceSystemModalDialogClose, sceSystemModalDialogClose@@0x5A121D1151471D2A\n"
    "sceSystemModalDialogClose:\n");

asm(".global sceSystemModalDialogOpen\n"
    ".type   sceSystemModalDialogOpen, @function\n"
    ".symver sceSystemModalDialogOpen, sceSystemModalDialogOpen@@0x693B5ACBCDAA24CF\n"
    "sceSystemModalDialogOpen:\n");

asm(".global sceSystemServiceAcquireBgmCpuBudget\n"
    ".type   sceSystemServiceAcquireBgmCpuBudget, @function\n"
    ".symver sceSystemServiceAcquireBgmCpuBudget, sceSystemServiceAcquireBgmCpuBudget@@0x0033B6F89E85D050\n"
    "sceSystemServiceAcquireBgmCpuBudget:\n");

asm(".global sceSystemServiceAcquireFb0\n"
    ".type   sceSystemServiceAcquireFb0, @function\n"
    ".symver sceSystemServiceAcquireFb0, sceSystemServiceAcquireFb0@@0xD33EECAEE94DB7B5\n"
    "sceSystemServiceAcquireFb0:\n");

asm(".global sceSystemServiceActivateHevc\n"
    ".type   sceSystemServiceActivateHevc, @function\n"
    ".symver sceSystemServiceActivateHevc, sceSystemServiceActivateHevc@@0xFB6B977EBAD00B29\n"
    "sceSystemServiceActivateHevc:\n");

asm(".global sceSystemServiceActivateHevcAbort\n"
    ".type   sceSystemServiceActivateHevcAbort, @function\n"
    ".symver sceSystemServiceActivateHevcAbort, sceSystemServiceActivateHevcAbort@@0x55703C4934F9DBDC\n"
    "sceSystemServiceActivateHevcAbort:\n");

asm(".global sceSystemServiceActivateHevcGetStatus\n"
    ".type   sceSystemServiceActivateHevcGetStatus, @function\n"
    ".symver sceSystemServiceActivateHevcGetStatus, sceSystemServiceActivateHevcGetStatus@@0x00F4BCD83DD6A780\n"
    "sceSystemServiceActivateHevcGetStatus:\n");

asm(".global sceSystemServiceActivateHevcInit\n"
    ".type   sceSystemServiceActivateHevcInit, @function\n"
    ".symver sceSystemServiceActivateHevcInit, sceSystemServiceActivateHevcInit@@0x0608CF81B5CA6231\n"
    "sceSystemServiceActivateHevcInit:\n");

asm(".global sceSystemServiceActivateHevcIsActivated\n"
    ".type   sceSystemServiceActivateHevcIsActivated, @function\n"
    ".symver sceSystemServiceActivateHevcIsActivated, sceSystemServiceActivateHevcIsActivated@@0xD871DF76B4FEAE74\n"
    "sceSystemServiceActivateHevcIsActivated:\n");

asm(".global sceSystemServiceActivateHevcSoft\n"
    ".type   sceSystemServiceActivateHevcSoft, @function\n"
    ".symver sceSystemServiceActivateHevcSoft, sceSystemServiceActivateHevcSoft@@0x007D6B4CA882A8DB\n"
    "sceSystemServiceActivateHevcSoft:\n");

asm(".global sceSystemServiceActivateHevcSoftAbort\n"
    ".type   sceSystemServiceActivateHevcSoftAbort, @function\n"
    ".symver sceSystemServiceActivateHevcSoftAbort, sceSystemServiceActivateHevcSoftAbort@@0xB3AB9C43DD015B78\n"
    "sceSystemServiceActivateHevcSoftAbort:\n");

asm(".global sceSystemServiceActivateHevcSoftGetStatus\n"
    ".type   sceSystemServiceActivateHevcSoftGetStatus, @function\n"
    ".symver sceSystemServiceActivateHevcSoftGetStatus, sceSystemServiceActivateHevcSoftGetStatus@@0x3320EFC61F3E7242\n"
    "sceSystemServiceActivateHevcSoftGetStatus:\n");

asm(".global sceSystemServiceActivateHevcSoftInit\n"
    ".type   sceSystemServiceActivateHevcSoftInit, @function\n"
    ".symver sceSystemServiceActivateHevcSoftInit, sceSystemServiceActivateHevcSoftInit@@0xCAD314EB1D679665\n"
    "sceSystemServiceActivateHevcSoftInit:\n");

asm(".global sceSystemServiceActivateHevcSoftIsActivated\n"
    ".type   sceSystemServiceActivateHevcSoftIsActivated, @function\n"
    ".symver sceSystemServiceActivateHevcSoftIsActivated, sceSystemServiceActivateHevcSoftIsActivated@@0x76355ED3A623CE42\n"
    "sceSystemServiceActivateHevcSoftIsActivated:\n");

asm(".global sceSystemServiceActivateHevcSoftStart\n"
    ".type   sceSystemServiceActivateHevcSoftStart, @function\n"
    ".symver sceSystemServiceActivateHevcSoftStart, sceSystemServiceActivateHevcSoftStart@@0x3CD3B6C650D57738\n"
    "sceSystemServiceActivateHevcSoftStart:\n");

asm(".global sceSystemServiceActivateHevcSoftTerm\n"
    ".type   sceSystemServiceActivateHevcSoftTerm, @function\n"
    ".symver sceSystemServiceActivateHevcSoftTerm, sceSystemServiceActivateHevcSoftTerm@@0x003DAC0122B5EB4D\n"
    "sceSystemServiceActivateHevcSoftTerm:\n");

asm(".global sceSystemServiceActivateHevcStart\n"
    ".type   sceSystemServiceActivateHevcStart, @function\n"
    ".symver sceSystemServiceActivateHevcStart, sceSystemServiceActivateHevcStart@@0x13D15DBACCA49420\n"
    "sceSystemServiceActivateHevcStart:\n");

asm(".global sceSystemServiceActivateHevcTerm\n"
    ".type   sceSystemServiceActivateHevcTerm, @function\n"
    ".symver sceSystemServiceActivateHevcTerm, sceSystemServiceActivateHevcTerm@@0xB489948064921E97\n"
    "sceSystemServiceActivateHevcTerm:\n");

asm(".global sceSystemServiceActivateMpeg2Abort\n"
    ".type   sceSystemServiceActivateMpeg2Abort, @function\n"
    ".symver sceSystemServiceActivateMpeg2Abort, sceSystemServiceActivateMpeg2Abort@@0x001679F70EF34AC3\n"
    "sceSystemServiceActivateMpeg2Abort:\n");

asm(".global sceSystemServiceActivateMpeg2GetStatus\n"
    ".type   sceSystemServiceActivateMpeg2GetStatus, @function\n"
    ".symver sceSystemServiceActivateMpeg2GetStatus, sceSystemServiceActivateMpeg2GetStatus@@0x00594F05E68D921E\n"
    "sceSystemServiceActivateMpeg2GetStatus:\n");

asm(".global sceSystemServiceActivateMpeg2Init\n"
    ".type   sceSystemServiceActivateMpeg2Init, @function\n"
    ".symver sceSystemServiceActivateMpeg2Init, sceSystemServiceActivateMpeg2Init@@0x3E445358D048E084\n"
    "sceSystemServiceActivateMpeg2Init:\n");

asm(".global sceSystemServiceActivateMpeg2IsActivated\n"
    ".type   sceSystemServiceActivateMpeg2IsActivated, @function\n"
    ".symver sceSystemServiceActivateMpeg2IsActivated, sceSystemServiceActivateMpeg2IsActivated@@0x69565BF7AD5B5815\n"
    "sceSystemServiceActivateMpeg2IsActivated:\n");

asm(".global sceSystemServiceActivateMpeg2Start\n"
    ".type   sceSystemServiceActivateMpeg2Start, @function\n"
    ".symver sceSystemServiceActivateMpeg2Start, sceSystemServiceActivateMpeg2Start@@0x00EF330D275029D5\n"
    "sceSystemServiceActivateMpeg2Start:\n");

asm(".global sceSystemServiceActivateMpeg2Term\n"
    ".type   sceSystemServiceActivateMpeg2Term, @function\n"
    ".symver sceSystemServiceActivateMpeg2Term, sceSystemServiceActivateMpeg2Term@@0x26322CA570DB2FAA\n"
    "sceSystemServiceActivateMpeg2Term:\n");

asm(".global sceSystemServiceAddLocalProcess\n"
    ".type   sceSystemServiceAddLocalProcess, @function\n"
    ".symver sceSystemServiceAddLocalProcess, sceSystemServiceAddLocalProcess@@0xD1C97C4AEC28B0F4\n"
    "sceSystemServiceAddLocalProcess:\n");

asm(".global sceSystemServiceAddLocalProcessForJvm\n"
    ".type   sceSystemServiceAddLocalProcessForJvm, @function\n"
    ".symver sceSystemServiceAddLocalProcessForJvm, sceSystemServiceAddLocalProcessForJvm@@0x8CF29AA5540B5FBD\n"
    "sceSystemServiceAddLocalProcessForJvm:\n");

asm(".global sceSystemServiceAddLocalProcessForPs2Emu\n"
    ".type   sceSystemServiceAddLocalProcessForPs2Emu, @function\n"
    ".symver sceSystemServiceAddLocalProcessForPs2Emu, sceSystemServiceAddLocalProcessForPs2Emu@@0xB4875752148BC8E5\n"
    "sceSystemServiceAddLocalProcessForPs2Emu:\n");

asm(".global sceSystemServiceAddLocalProcessForPsmKit\n"
    ".type   sceSystemServiceAddLocalProcessForPsmKit, @function\n"
    ".symver sceSystemServiceAddLocalProcessForPsmKit, sceSystemServiceAddLocalProcessForPsmKit@@0x725B6C841AC32C2D\n"
    "sceSystemServiceAddLocalProcessForPsmKit:\n");

asm(".global sceSystemServiceAppGetAppInstallStatus\n"
    ".type   sceSystemServiceAppGetAppInstallStatus, @function\n"
    ".symver sceSystemServiceAppGetAppInstallStatus, sceSystemServiceAppGetAppInstallStatus@@0x1CE4A7C23B2264C9\n"
    "sceSystemServiceAppGetAppInstallStatus:\n");

asm(".global sceSystemServiceChangeAcpClock\n"
    ".type   sceSystemServiceChangeAcpClock, @function\n"
    ".symver sceSystemServiceChangeAcpClock, sceSystemServiceChangeAcpClock@@0x148F95A8676DB6F2\n"
    "sceSystemServiceChangeAcpClock:\n");

asm(".global sceSystemServiceChangeClock\n"
    ".type   sceSystemServiceChangeClock, @function\n"
    ".symver sceSystemServiceChangeClock, sceSystemServiceChangeClock@@0x99B39CD26804E062\n"
    "sceSystemServiceChangeClock:\n");

asm(".global sceSystemServiceChangeCpuClock\n"
    ".type   sceSystemServiceChangeCpuClock, @function\n"
    ".symver sceSystemServiceChangeCpuClock, sceSystemServiceChangeCpuClock@@0x79CEF6BEDDD6110A\n"
    "sceSystemServiceChangeCpuClock:\n");

asm(".global sceSystemServiceChangeCpuPstate\n"
    ".type   sceSystemServiceChangeCpuPstate, @function\n"
    ".symver sceSystemServiceChangeCpuPstate, sceSystemServiceChangeCpuPstate@@0x630ACB6B431E923C\n"
    "sceSystemServiceChangeCpuPstate:\n");

asm(".global sceSystemServiceChangeGpuClock\n"
    ".type   sceSystemServiceChangeGpuClock, @function\n"
    ".symver sceSystemServiceChangeGpuClock, sceSystemServiceChangeGpuClock@@0x6794605780A1C318\n"
    "sceSystemServiceChangeGpuClock:\n");

asm(".global sceSystemServiceChangeMemPstate\n"
    ".type   sceSystemServiceChangeMemPstate, @function\n"
    ".symver sceSystemServiceChangeMemPstate, sceSystemServiceChangeMemPstate@@0xD4E71068862B4E76\n"
    "sceSystemServiceChangeMemPstate:\n");

asm(".global sceSystemServiceChangeMemoryClock\n"
    ".type   sceSystemServiceChangeMemoryClock, @function\n"
    ".symver sceSystemServiceChangeMemoryClock, sceSystemServiceChangeMemoryClock@@0x2C5A34D115B3A915\n"
    "sceSystemServiceChangeMemoryClock:\n");

asm(".global sceSystemServiceChangeMemoryClockToBaseMode\n"
    ".type   sceSystemServiceChangeMemoryClockToBaseMode, @function\n"
    ".symver sceSystemServiceChangeMemoryClockToBaseMode, sceSystemServiceChangeMemoryClockToBaseMode@@0x332057B250C4FB6A\n"
    "sceSystemServiceChangeMemoryClockToBaseMode:\n");

asm(".global sceSystemServiceChangeMemoryClockToDefault\n"
    ".type   sceSystemServiceChangeMemoryClockToDefault, @function\n"
    ".symver sceSystemServiceChangeMemoryClockToDefault, sceSystemServiceChangeMemoryClockToDefault@@0xAAFF97F20A33A85E\n"
    "sceSystemServiceChangeMemoryClockToDefault:\n");

asm(".global sceSystemServiceChangeMemoryClockToMultiMediaMode\n"
    ".type   sceSystemServiceChangeMemoryClockToMultiMediaMode, @function\n"
    ".symver sceSystemServiceChangeMemoryClockToMultiMediaMode, sceSystemServiceChangeMemoryClockToMultiMediaMode@@0x7CEB04E694E27AA6\n"
    "sceSystemServiceChangeMemoryClockToMultiMediaMode:\n");

asm(".global sceSystemServiceChangeNumberOfGpuCu\n"
    ".type   sceSystemServiceChangeNumberOfGpuCu, @function\n"
    ".symver sceSystemServiceChangeNumberOfGpuCu, sceSystemServiceChangeNumberOfGpuCu@@0xE4C2E9A45259C97E\n"
    "sceSystemServiceChangeNumberOfGpuCu:\n");

asm(".global sceSystemServiceChangeSamuClock\n"
    ".type   sceSystemServiceChangeSamuClock, @function\n"
    ".symver sceSystemServiceChangeSamuClock, sceSystemServiceChangeSamuClock@@0x9604E5200109DF73\n"
    "sceSystemServiceChangeSamuClock:\n");

asm(".global sceSystemServiceChangeUvdClock\n"
    ".type   sceSystemServiceChangeUvdClock, @function\n"
    ".symver sceSystemServiceChangeUvdClock, sceSystemServiceChangeUvdClock@@0x050522EC05BEDAD4\n"
    "sceSystemServiceChangeUvdClock:\n");

asm(".global sceSystemServiceChangeVceClock\n"
    ".type   sceSystemServiceChangeVceClock, @function\n"
    ".symver sceSystemServiceChangeVceClock, sceSystemServiceChangeVceClock@@0x7F382E5C143336F2\n"
    "sceSystemServiceChangeVceClock:\n");

asm(".global sceSystemServiceDeclareReadyForSuspend\n"
    ".type   sceSystemServiceDeclareReadyForSuspend, @function\n"
    ".symver sceSystemServiceDeclareReadyForSuspend, sceSystemServiceDeclareReadyForSuspend@@0x12A70F037BA044FF\n"
    "sceSystemServiceDeclareReadyForSuspend:\n");

asm(".global sceSystemServiceDisableMediaPlay\n"
    ".type   sceSystemServiceDisableMediaPlay, @function\n"
    ".symver sceSystemServiceDisableMediaPlay, sceSystemServiceDisableMediaPlay@@0xEB89E417B2C693CC\n"
    "sceSystemServiceDisableMediaPlay:\n");

asm(".global sceSystemServiceDisableMusicPlayer\n"
    ".type   sceSystemServiceDisableMusicPlayer, @function\n"
    ".symver sceSystemServiceDisableMusicPlayer, sceSystemServiceDisableMusicPlayer@@0xC75501F5BC0348EC\n"
    "sceSystemServiceDisableMusicPlayer:\n");

asm(".global sceSystemServiceDisableNoticeScreenSkipFlagAutoSet\n"
    ".type   sceSystemServiceDisableNoticeScreenSkipFlagAutoSet, @function\n"
    ".symver sceSystemServiceDisableNoticeScreenSkipFlagAutoSet, sceSystemServiceDisableNoticeScreenSkipFlagAutoSet@@0xF0BA3A66FF786A1A\n"
    "sceSystemServiceDisableNoticeScreenSkipFlagAutoSet:\n");

asm(".global sceSystemServiceDisablePartyVoice\n"
    ".type   sceSystemServiceDisablePartyVoice, @function\n"
    ".symver sceSystemServiceDisablePartyVoice, sceSystemServiceDisablePartyVoice@@0xE3942B16F524AE38\n"
    "sceSystemServiceDisablePartyVoice:\n");

asm(".global sceSystemServiceDisablePersonalEyeToEyeDistanceSetting\n"
    ".type   sceSystemServiceDisablePersonalEyeToEyeDistanceSetting, @function\n"
    ".symver sceSystemServiceDisablePersonalEyeToEyeDistanceSetting, sceSystemServiceDisablePersonalEyeToEyeDistanceSetting@@0x32BD488106917DFD\n"
    "sceSystemServiceDisablePersonalEyeToEyeDistanceSetting:\n");

asm(".global sceSystemServiceDisableSuspendConfirmationDialog\n"
    ".type   sceSystemServiceDisableSuspendConfirmationDialog, @function\n"
    ".symver sceSystemServiceDisableSuspendConfirmationDialog, sceSystemServiceDisableSuspendConfirmationDialog@@0x3D0F928D7020DC43\n"
    "sceSystemServiceDisableSuspendConfirmationDialog:\n");

asm(".global sceSystemServiceDisableSuspendNotification\n"
    ".type   sceSystemServiceDisableSuspendNotification, @function\n"
    ".symver sceSystemServiceDisableSuspendNotification, sceSystemServiceDisableSuspendNotification@@0x322D2AC026FEAEFA\n"
    "sceSystemServiceDisableSuspendNotification:\n");

asm(".global sceSystemServiceDisableVoiceRecognition\n"
    ".type   sceSystemServiceDisableVoiceRecognition, @function\n"
    ".symver sceSystemServiceDisableVoiceRecognition, sceSystemServiceDisableVoiceRecognition@@0x7773A7A0AB4D8C68\n"
    "sceSystemServiceDisableVoiceRecognition:\n");

asm(".global sceSystemServiceEnablePersonalEyeToEyeDistanceSetting\n"
    ".type   sceSystemServiceEnablePersonalEyeToEyeDistanceSetting, @function\n"
    ".symver sceSystemServiceEnablePersonalEyeToEyeDistanceSetting, sceSystemServiceEnablePersonalEyeToEyeDistanceSetting@@0x003B78AB594436B2\n"
    "sceSystemServiceEnablePersonalEyeToEyeDistanceSetting:\n");

asm(".global sceSystemServiceEnableSuspendConfirmationDialog\n"
    ".type   sceSystemServiceEnableSuspendConfirmationDialog, @function\n"
    ".symver sceSystemServiceEnableSuspendConfirmationDialog, sceSystemServiceEnableSuspendConfirmationDialog@@0x467DF63B93C3966A\n"
    "sceSystemServiceEnableSuspendConfirmationDialog:\n");

asm(".global sceSystemServiceEnableSuspendNotification\n"
    ".type   sceSystemServiceEnableSuspendNotification, @function\n"
    ".symver sceSystemServiceEnableSuspendNotification, sceSystemServiceEnableSuspendNotification@@0x6B92A38EAE8781C5\n"
    "sceSystemServiceEnableSuspendNotification:\n");

asm(".global sceSystemServiceGetAppCategoryType\n"
    ".type   sceSystemServiceGetAppCategoryType, @function\n"
    ".symver sceSystemServiceGetAppCategoryType, sceSystemServiceGetAppCategoryType@@0x0042D7C986C135C4\n"
    "sceSystemServiceGetAppCategoryType:\n");

asm(".global sceSystemServiceGetAppFocusedAppStatus\n"
    ".type   sceSystemServiceGetAppFocusedAppStatus, @function\n"
    ".symver sceSystemServiceGetAppFocusedAppStatus, sceSystemServiceGetAppFocusedAppStatus@@0xC6313BC4B7EB2D49\n"
    "sceSystemServiceGetAppFocusedAppStatus:\n");

asm(".global sceSystemServiceGetAppId\n"
    ".type   sceSystemServiceGetAppId, @function\n"
    ".symver sceSystemServiceGetAppId, sceSystemServiceGetAppId@@0x4ED22D8A45B0060B\n"
    "sceSystemServiceGetAppId:\n");

asm(".global sceSystemServiceGetAppIdListOfBigApp\n"
    ".type   sceSystemServiceGetAppIdListOfBigApp, @function\n"
    ".symver sceSystemServiceGetAppIdListOfBigApp, sceSystemServiceGetAppIdListOfBigApp@@0x009EFA54EFC93929\n"
    "sceSystemServiceGetAppIdListOfBigApp:\n");

asm(".global sceSystemServiceGetAppIdOfRunningBigApp\n"
    ".type   sceSystemServiceGetAppIdOfRunningBigApp, @function\n"
    ".symver sceSystemServiceGetAppIdOfRunningBigApp, sceSystemServiceGetAppIdOfRunningBigApp@@0x3704F6479968F0FF\n"
    "sceSystemServiceGetAppIdOfRunningBigApp:\n");

asm(".global sceSystemServiceGetAppLaunchedUser\n"
    ".type   sceSystemServiceGetAppLaunchedUser, @function\n"
    ".symver sceSystemServiceGetAppLaunchedUser, sceSystemServiceGetAppLaunchedUser@@0x0591807FE1746E52\n"
    "sceSystemServiceGetAppLaunchedUser:\n");

asm(".global sceSystemServiceGetAppStatus\n"
    ".type   sceSystemServiceGetAppStatus, @function\n"
    ".symver sceSystemServiceGetAppStatus, sceSystemServiceGetAppStatus@@0xB794A15748D61051\n"
    "sceSystemServiceGetAppStatus:\n");

asm(".global sceSystemServiceGetAppTitleId\n"
    ".type   sceSystemServiceGetAppTitleId, @function\n"
    ".symver sceSystemServiceGetAppTitleId, sceSystemServiceGetAppTitleId@@0x00D18988D3D8CE3E\n"
    "sceSystemServiceGetAppTitleId:\n");

asm(".global sceSystemServiceGetAppType\n"
    ".type   sceSystemServiceGetAppType, @function\n"
    ".symver sceSystemServiceGetAppType, sceSystemServiceGetAppType@@0x60B6E10174B6D02D\n"
    "sceSystemServiceGetAppType:\n");

asm(".global sceSystemServiceGetDbgExecutablePath\n"
    ".type   sceSystemServiceGetDbgExecutablePath, @function\n"
    ".symver sceSystemServiceGetDbgExecutablePath, sceSystemServiceGetDbgExecutablePath@@0xD130DF3FB4787E24\n"
    "sceSystemServiceGetDbgExecutablePath:\n");

asm(".global sceSystemServiceGetDisplaySafeAreaInfo\n"
    ".type   sceSystemServiceGetDisplaySafeAreaInfo, @function\n"
    ".symver sceSystemServiceGetDisplaySafeAreaInfo, sceSystemServiceGetDisplaySafeAreaInfo@@0xD67DFBAB506F7396\n"
    "sceSystemServiceGetDisplaySafeAreaInfo:\n");

asm(".global sceSystemServiceGetEventForDaemon\n"
    ".type   sceSystemServiceGetEventForDaemon, @function\n"
    ".symver sceSystemServiceGetEventForDaemon, sceSystemServiceGetEventForDaemon@@0x2458376B3E484CDE\n"
    "sceSystemServiceGetEventForDaemon:\n");

asm(".global sceSystemServiceGetGpuLoadEmulationMode\n"
    ".type   sceSystemServiceGetGpuLoadEmulationMode, @function\n"
    ".symver sceSystemServiceGetGpuLoadEmulationMode, sceSystemServiceGetGpuLoadEmulationMode@@0x00E229B254CC57E7\n"
    "sceSystemServiceGetGpuLoadEmulationMode:\n");

asm(".global sceSystemServiceGetHdrToneMapLuminance\n"
    ".type   sceSystemServiceGetHdrToneMapLuminance, @function\n"
    ".symver sceSystemServiceGetHdrToneMapLuminance, sceSystemServiceGetHdrToneMapLuminance@@0x98FA4FC6FE4266DE\n"
    "sceSystemServiceGetHdrToneMapLuminance:\n");

asm(".global sceSystemServiceGetLocalProcessStatusList\n"
    ".type   sceSystemServiceGetLocalProcessStatusList, @function\n"
    ".symver sceSystemServiceGetLocalProcessStatusList, sceSystemServiceGetLocalProcessStatusList@@0x64D22E263A9DB602\n"
    "sceSystemServiceGetLocalProcessStatusList:\n");

asm(".global sceSystemServiceGetMainAppTitleId\n"
    ".type   sceSystemServiceGetMainAppTitleId, @function\n"
    ".symver sceSystemServiceGetMainAppTitleId, sceSystemServiceGetMainAppTitleId@@0xE2F784D17888BA00\n"
    "sceSystemServiceGetMainAppTitleId:\n");

asm(".global sceSystemServiceGetNoticeScreenSkipFlag\n"
    ".type   sceSystemServiceGetNoticeScreenSkipFlag, @function\n"
    ".symver sceSystemServiceGetNoticeScreenSkipFlag, sceSystemServiceGetNoticeScreenSkipFlag@@0xDD14396907E7B2D5\n"
    "sceSystemServiceGetNoticeScreenSkipFlag:\n");

asm(".global sceSystemServiceGetPSButtonEvent\n"
    ".type   sceSystemServiceGetPSButtonEvent, @function\n"
    ".symver sceSystemServiceGetPSButtonEvent, sceSystemServiceGetPSButtonEvent@@0x81B501A870848002\n"
    "sceSystemServiceGetPSButtonEvent:\n");

asm(".global sceSystemServiceGetParentSocket\n"
    ".type   sceSystemServiceGetParentSocket, @function\n"
    ".symver sceSystemServiceGetParentSocket, sceSystemServiceGetParentSocket@@0x50C225ACE9463505\n"
    "sceSystemServiceGetParentSocket:\n");

asm(".global sceSystemServiceGetParentSocketForJvm\n"
    ".type   sceSystemServiceGetParentSocketForJvm, @function\n"
    ".symver sceSystemServiceGetParentSocketForJvm, sceSystemServiceGetParentSocketForJvm@@0xCEA8E467954A1528\n"
    "sceSystemServiceGetParentSocketForJvm:\n");

asm(".global sceSystemServiceGetParentSocketForPs2Emu\n"
    ".type   sceSystemServiceGetParentSocketForPs2Emu, @function\n"
    ".symver sceSystemServiceGetParentSocketForPs2Emu, sceSystemServiceGetParentSocketForPs2Emu@@0xAA13C9D447EA2E34\n"
    "sceSystemServiceGetParentSocketForPs2Emu:\n");

asm(".global sceSystemServiceGetParentSocketForPsmKit\n"
    ".type   sceSystemServiceGetParentSocketForPsmKit, @function\n"
    ".symver sceSystemServiceGetParentSocketForPsmKit, sceSystemServiceGetParentSocketForPsmKit@@0xE1962E488F22D9A3\n"
    "sceSystemServiceGetParentSocketForPsmKit:\n");

asm(".global sceSystemServiceGetPlatformPrivacyDefinitionData\n"
    ".type   sceSystemServiceGetPlatformPrivacyDefinitionData, @function\n"
    ".symver sceSystemServiceGetPlatformPrivacyDefinitionData, sceSystemServiceGetPlatformPrivacyDefinitionData@@0x00E6ED9678B3D1DB\n"
    "sceSystemServiceGetPlatformPrivacyDefinitionData:\n");

asm(".global sceSystemServiceGetPlatformPrivacyDefinitionVersion\n"
    ".type   sceSystemServiceGetPlatformPrivacyDefinitionVersion, @function\n"
    ".symver sceSystemServiceGetPlatformPrivacyDefinitionVersion, sceSystemServiceGetPlatformPrivacyDefinitionVersion@@0xB792BE21E3150F54\n"
    "sceSystemServiceGetPlatformPrivacyDefinitionVersion:\n");

asm(".global sceSystemServiceGetPlatformPrivacySetting\n"
    ".type   sceSystemServiceGetPlatformPrivacySetting, @function\n"
    ".symver sceSystemServiceGetPlatformPrivacySetting, sceSystemServiceGetPlatformPrivacySetting@@0x86FA0B62173872AD\n"
    "sceSystemServiceGetPlatformPrivacySetting:\n");

asm(".global sceSystemServiceGetRecentLotusPushedButton\n"
    ".type   sceSystemServiceGetRecentLotusPushedButton, @function\n"
    ".symver sceSystemServiceGetRecentLotusPushedButton, sceSystemServiceGetRecentLotusPushedButton@@0x34A6D4859594D457\n"
    "sceSystemServiceGetRecentLotusPushedButton:\n");

asm(".global sceSystemServiceGetRemoteplayStatus\n"
    ".type   sceSystemServiceGetRemoteplayStatus, @function\n"
    ".symver sceSystemServiceGetRemoteplayStatus, sceSystemServiceGetRemoteplayStatus@@0x19EB65F91A848554\n"
    "sceSystemServiceGetRemoteplayStatus:\n");

asm(".global sceSystemServiceGetRenderingMode\n"
    ".type   sceSystemServiceGetRenderingMode, @function\n"
    ".symver sceSystemServiceGetRenderingMode, sceSystemServiceGetRenderingMode@@0x8C0EB6F4F70C08A5\n"
    "sceSystemServiceGetRenderingMode:\n");

asm(".global sceSystemServiceGetStatus\n"
    ".type   sceSystemServiceGetStatus, @function\n"
    ".symver sceSystemServiceGetStatus, sceSystemServiceGetStatus@@0xACFA3AB55F03F5B3\n"
    "sceSystemServiceGetStatus:\n");

asm(".global sceSystemServiceGetSubAppTitleId\n"
    ".type   sceSystemServiceGetSubAppTitleId, @function\n"
    ".symver sceSystemServiceGetSubAppTitleId, sceSystemServiceGetSubAppTitleId@@0x1308F2C2FDD6E100\n"
    "sceSystemServiceGetSubAppTitleId:\n");

asm(".global sceSystemServiceGetSubAppTitleIdForSP\n"
    ".type   sceSystemServiceGetSubAppTitleIdForSP, @function\n"
    ".symver sceSystemServiceGetSubAppTitleIdForSP, sceSystemServiceGetSubAppTitleIdForSP@@0x0029CF0A42C1B6B8\n"
    "sceSystemServiceGetSubAppTitleIdForSP:\n");

asm(".global sceSystemServiceGetTitleWorkaroundInfo\n"
    ".type   sceSystemServiceGetTitleWorkaroundInfo, @function\n"
    ".symver sceSystemServiceGetTitleWorkaroundInfo, sceSystemServiceGetTitleWorkaroundInfo@@0x56BBE9A091284925\n"
    "sceSystemServiceGetTitleWorkaroundInfo:\n");

asm(".global sceSystemServiceGetUIStatus\n"
    ".type   sceSystemServiceGetUIStatus, @function\n"
    ".symver sceSystemServiceGetUIStatus, sceSystemServiceGetUIStatus@@0x27CB7CB77795A0C8\n"
    "sceSystemServiceGetUIStatus:\n");

asm(".global sceSystemServiceGetVersionNumberOfCameraCalibrationData\n"
    ".type   sceSystemServiceGetVersionNumberOfCameraCalibrationData, @function\n"
    ".symver sceSystemServiceGetVersionNumberOfCameraCalibrationData, sceSystemServiceGetVersionNumberOfCameraCalibrationData@@0xB3839C2EA2EC2A7D\n"
    "sceSystemServiceGetVersionNumberOfCameraCalibrationData:\n");

asm(".global sceSystemServiceHideSplashScreen\n"
    ".type   sceSystemServiceHideSplashScreen, @function\n"
    ".symver sceSystemServiceHideSplashScreen, sceSystemServiceHideSplashScreen@@0x568E55F0A0300A69\n"
    "sceSystemServiceHideSplashScreen:\n");

asm(".global sceSystemServiceInitializeForShellCore\n"
    ".type   sceSystemServiceInitializeForShellCore, @function\n"
    ".symver sceSystemServiceInitializeForShellCore, sceSystemServiceInitializeForShellCore@@0x803E30876FA7BAE5\n"
    "sceSystemServiceInitializeForShellCore:\n");

asm(".global sceSystemServiceInitializePlayerDialogParam\n"
    ".type   sceSystemServiceInitializePlayerDialogParam, @function\n"
    ".symver sceSystemServiceInitializePlayerDialogParam, sceSystemServiceInitializePlayerDialogParam@@0x9B9098297DB4C1F8\n"
    "sceSystemServiceInitializePlayerDialogParam:\n");

asm(".global sceSystemServiceInvokeAppLaunchLink\n"
    ".type   sceSystemServiceInvokeAppLaunchLink, @function\n"
    ".symver sceSystemServiceInvokeAppLaunchLink, sceSystemServiceInvokeAppLaunchLink@@0x00AD36B4569E2728\n"
    "sceSystemServiceInvokeAppLaunchLink:\n");

asm(".global sceSystemServiceIsAppSuspended\n"
    ".type   sceSystemServiceIsAppSuspended, @function\n"
    ".symver sceSystemServiceIsAppSuspended, sceSystemServiceIsAppSuspended@@0x00775E584C250C55\n"
    "sceSystemServiceIsAppSuspended:\n");

asm(".global sceSystemServiceIsBgmCpuBudgetAvailable\n"
    ".type   sceSystemServiceIsBgmCpuBudgetAvailable, @function\n"
    ".symver sceSystemServiceIsBgmCpuBudgetAvailable, sceSystemServiceIsBgmCpuBudgetAvailable@@0xD5EA008DEE5CB720\n"
    "sceSystemServiceIsBgmCpuBudgetAvailable:\n");

asm(".global sceSystemServiceIsBgmPlaying\n"
    ".type   sceSystemServiceIsBgmPlaying, @function\n"
    ".symver sceSystemServiceIsBgmPlaying, sceSystemServiceIsBgmPlaying@@0x498A9AA8BB9053AC\n"
    "sceSystemServiceIsBgmPlaying:\n");

asm(".global sceSystemServiceIsEyeToEyeDistanceAdjusted\n"
    ".type   sceSystemServiceIsEyeToEyeDistanceAdjusted, @function\n"
    ".symver sceSystemServiceIsEyeToEyeDistanceAdjusted, sceSystemServiceIsEyeToEyeDistanceAdjusted@@0x3B8C7507B6974581\n"
    "sceSystemServiceIsEyeToEyeDistanceAdjusted:\n");

asm(".global sceSystemServiceIsGameLiveStreamingOnAir\n"
    ".type   sceSystemServiceIsGameLiveStreamingOnAir, @function\n"
    ".symver sceSystemServiceIsGameLiveStreamingOnAir, sceSystemServiceIsGameLiveStreamingOnAir@@0x001C60364951A4AB\n"
    "sceSystemServiceIsGameLiveStreamingOnAir:\n");

asm(".global sceSystemServiceIsScreenSaverOn\n"
    ".type   sceSystemServiceIsScreenSaverOn, @function\n"
    ".symver sceSystemServiceIsScreenSaverOn, sceSystemServiceIsScreenSaverOn@@0x6CC0DBA1F58535F4\n"
    "sceSystemServiceIsScreenSaverOn:\n");

asm(".global sceSystemServiceIsShellUiFgAndGameBgCpuMode\n"
    ".type   sceSystemServiceIsShellUiFgAndGameBgCpuMode, @function\n"
    ".symver sceSystemServiceIsShellUiFgAndGameBgCpuMode, sceSystemServiceIsShellUiFgAndGameBgCpuMode@@0x2901720E48008D5B\n"
    "sceSystemServiceIsShellUiFgAndGameBgCpuMode:\n");

asm(".global sceSystemServiceKillApp\n"
    ".type   sceSystemServiceKillApp, @function\n"
    ".symver sceSystemServiceKillApp, sceSystemServiceKillApp@@0x378464C8987B16D0\n"
    "sceSystemServiceKillApp:\n");

asm(".global sceSystemServiceKillLocalProcess\n"
    ".type   sceSystemServiceKillLocalProcess, @function\n"
    ".symver sceSystemServiceKillLocalProcess, sceSystemServiceKillLocalProcess@@0xEA3A59634594C0B3\n"
    "sceSystemServiceKillLocalProcess:\n");

asm(".global sceSystemServiceKillLocalProcessForJvm\n"
    ".type   sceSystemServiceKillLocalProcessForJvm, @function\n"
    ".symver sceSystemServiceKillLocalProcessForJvm, sceSystemServiceKillLocalProcessForJvm@@0xD932792B30BBDE06\n"
    "sceSystemServiceKillLocalProcessForJvm:\n");

asm(".global sceSystemServiceKillLocalProcessForPs2Emu\n"
    ".type   sceSystemServiceKillLocalProcessForPs2Emu, @function\n"
    ".symver sceSystemServiceKillLocalProcessForPs2Emu, sceSystemServiceKillLocalProcessForPs2Emu@@0x7CAA894E7A19F02F\n"
    "sceSystemServiceKillLocalProcessForPs2Emu:\n");

asm(".global sceSystemServiceKillLocalProcessForPsmKit\n"
    ".type   sceSystemServiceKillLocalProcessForPsmKit, @function\n"
    ".symver sceSystemServiceKillLocalProcessForPsmKit, sceSystemServiceKillLocalProcessForPsmKit@@0xEDC4DCEEC7892DF4\n"
    "sceSystemServiceKillLocalProcessForPsmKit:\n");

asm(".global sceSystemServiceLaunchApp\n"
    ".type   sceSystemServiceLaunchApp, @function\n"
    ".symver sceSystemServiceLaunchApp, sceSystemServiceLaunchApp@@0x00978141DF035A01\n"
    "sceSystemServiceLaunchApp:\n");

asm(".global sceSystemServiceLaunchEventDetails\n"
    ".type   sceSystemServiceLaunchEventDetails, @function\n"
    ".symver sceSystemServiceLaunchEventDetails, sceSystemServiceLaunchEventDetails@@0xC17F7054569E81A3\n"
    "sceSystemServiceLaunchEventDetails:\n");

asm(".global sceSystemServiceLaunchPlayerDialog\n"
    ".type   sceSystemServiceLaunchPlayerDialog, @function\n"
    ".symver sceSystemServiceLaunchPlayerDialog, sceSystemServiceLaunchPlayerDialog@@0xB9A89E17E82514FB\n"
    "sceSystemServiceLaunchPlayerDialog:\n");

asm(".global sceSystemServiceLaunchStore\n"
    ".type   sceSystemServiceLaunchStore, @function\n"
    ".symver sceSystemServiceLaunchStore, sceSystemServiceLaunchStore@@0x663E4518940F171B\n"
    "sceSystemServiceLaunchStore:\n");

asm(".global sceSystemServiceLaunchTournamentList\n"
    ".type   sceSystemServiceLaunchTournamentList, @function\n"
    ".symver sceSystemServiceLaunchTournamentList, sceSystemServiceLaunchTournamentList@@0x1B9030CD69C7C64B\n"
    "sceSystemServiceLaunchTournamentList:\n");

asm(".global sceSystemServiceLaunchTournamentsTeamProfile\n"
    ".type   sceSystemServiceLaunchTournamentsTeamProfile, @function\n"
    ".symver sceSystemServiceLaunchTournamentsTeamProfile, sceSystemServiceLaunchTournamentsTeamProfile@@0xC0873DD9BD31EA19\n"
    "sceSystemServiceLaunchTournamentsTeamProfile:\n");

asm(".global sceSystemServiceLaunchUdsApp\n"
    ".type   sceSystemServiceLaunchUdsApp, @function\n"
    ".symver sceSystemServiceLaunchUdsApp, sceSystemServiceLaunchUdsApp@@0x60DA038DCD413C92\n"
    "sceSystemServiceLaunchUdsApp:\n");

asm(".global sceSystemServiceLaunchWebApp\n"
    ".type   sceSystemServiceLaunchWebApp, @function\n"
    ".symver sceSystemServiceLaunchWebApp, sceSystemServiceLaunchWebApp@@0x7F7E2A9FB5C0DD01\n"
    "sceSystemServiceLaunchWebApp:\n");

asm(".global sceSystemServiceLaunchWebBrowser\n"
    ".type   sceSystemServiceLaunchWebBrowser, @function\n"
    ".symver sceSystemServiceLaunchWebBrowser, sceSystemServiceLaunchWebBrowser@@0x00FB7858FB2F1B36\n"
    "sceSystemServiceLaunchWebBrowser:\n");

asm(".global sceSystemServiceLoadExec\n"
    ".type   sceSystemServiceLoadExec, @function\n"
    ".symver sceSystemServiceLoadExec, sceSystemServiceLoadExec@@0x26806A490B75CB20\n"
    "sceSystemServiceLoadExec:\n");

asm(".global sceSystemServiceLoadExecVideoServiceWebApp\n"
    ".type   sceSystemServiceLoadExecVideoServiceWebApp, @function\n"
    ".symver sceSystemServiceLoadExecVideoServiceWebApp, sceSystemServiceLoadExecVideoServiceWebApp@@0x0264EFA37453E6CB\n"
    "sceSystemServiceLoadExecVideoServiceWebApp:\n");

asm(".global sceSystemServiceNavigateToAnotherApp\n"
    ".type   sceSystemServiceNavigateToAnotherApp, @function\n"
    ".symver sceSystemServiceNavigateToAnotherApp, sceSystemServiceNavigateToAnotherApp@@0xF52703544AD1460C\n"
    "sceSystemServiceNavigateToAnotherApp:\n");

asm(".global sceSystemServiceNavigateToGoBack\n"
    ".type   sceSystemServiceNavigateToGoBack, @function\n"
    ".symver sceSystemServiceNavigateToGoBack, sceSystemServiceNavigateToGoBack@@0x7B81373081004B60\n"
    "sceSystemServiceNavigateToGoBack:\n");

asm(".global sceSystemServiceNavigateToGoBackWithValue\n"
    ".type   sceSystemServiceNavigateToGoBackWithValue, @function\n"
    ".symver sceSystemServiceNavigateToGoBackWithValue, sceSystemServiceNavigateToGoBackWithValue@@0x65EB9B2E13C38ADC\n"
    "sceSystemServiceNavigateToGoBackWithValue:\n");

asm(".global sceSystemServiceNavigateToGoHome\n"
    ".type   sceSystemServiceNavigateToGoHome, @function\n"
    ".symver sceSystemServiceNavigateToGoHome, sceSystemServiceNavigateToGoHome@@0x00C76A3D781C3765\n"
    "sceSystemServiceNavigateToGoHome:\n");

asm(".global sceSystemServiceNotifyBgmCoreTermination\n"
    ".type   sceSystemServiceNotifyBgmCoreTermination, @function\n"
    ".symver sceSystemServiceNotifyBgmCoreTermination, sceSystemServiceNotifyBgmCoreTermination@@0xAFC4323D16D30009\n"
    "sceSystemServiceNotifyBgmCoreTermination:\n");

asm(".global sceSystemServiceParamGetInt\n"
    ".type   sceSystemServiceParamGetInt, @function\n"
    ".symver sceSystemServiceParamGetInt, sceSystemServiceParamGetInt@@0x7D9A38F2E9FB2CAE\n"
    "sceSystemServiceParamGetInt:\n");

asm(".global sceSystemServiceParamGetString\n"
    ".type   sceSystemServiceParamGetString, @function\n"
    ".symver sceSystemServiceParamGetString, sceSystemServiceParamGetString@@0x0000000000000000\n"
    "sceSystemServiceParamGetString:\n");

asm(".global sceSystemServicePowerTick\n"
    ".type   sceSystemServicePowerTick, @function\n"
    ".symver sceSystemServicePowerTick, sceSystemServicePowerTick@@0x5DB6C90B713E2F93\n"
    "sceSystemServicePowerTick:\n");

asm(".global sceSystemServiceRaiseExceptionLocalProcess\n"
    ".type   sceSystemServiceRaiseExceptionLocalProcess, @function\n"
    ".symver sceSystemServiceRaiseExceptionLocalProcess, sceSystemServiceRaiseExceptionLocalProcess@@0x00DB17A796FECC51\n"
    "sceSystemServiceRaiseExceptionLocalProcess:\n");

asm(".global sceSystemServiceReceiveEvent\n"
    ".type   sceSystemServiceReceiveEvent, @function\n"
    ".symver sceSystemServiceReceiveEvent, sceSystemServiceReceiveEvent@@0xEB9E8B3104AB83A5\n"
    "sceSystemServiceReceiveEvent:\n");

asm(".global sceSystemServiceReenableMediaPlay\n"
    ".type   sceSystemServiceReenableMediaPlay, @function\n"
    ".symver sceSystemServiceReenableMediaPlay, sceSystemServiceReenableMediaPlay@@0xB889D8872EF16BE5\n"
    "sceSystemServiceReenableMediaPlay:\n");

asm(".global sceSystemServiceReenableMusicPlayer\n"
    ".type   sceSystemServiceReenableMusicPlayer, @function\n"
    ".symver sceSystemServiceReenableMusicPlayer, sceSystemServiceReenableMusicPlayer@@0xF643C2CFB3ABFB56\n"
    "sceSystemServiceReenableMusicPlayer:\n");

asm(".global sceSystemServiceReenablePartyVoice\n"
    ".type   sceSystemServiceReenablePartyVoice, @function\n"
    ".symver sceSystemServiceReenablePartyVoice, sceSystemServiceReenablePartyVoice@@0x854DDB4A517638AB\n"
    "sceSystemServiceReenablePartyVoice:\n");

asm(".global sceSystemServiceReenableVoiceRecognition\n"
    ".type   sceSystemServiceReenableVoiceRecognition, @function\n"
    ".symver sceSystemServiceReenableVoiceRecognition, sceSystemServiceReenableVoiceRecognition@@0x0071A14A867EF887\n"
    "sceSystemServiceReenableVoiceRecognition:\n");

asm(".global sceSystemServiceRegisterDaemon\n"
    ".type   sceSystemServiceRegisterDaemon, @function\n"
    ".symver sceSystemServiceRegisterDaemon, sceSystemServiceRegisterDaemon@@0x3E2DCAE3B5F0D2CB\n"
    "sceSystemServiceRegisterDaemon:\n");

asm(".global sceSystemServiceReleaseBgmCpuBudget\n"
    ".type   sceSystemServiceReleaseBgmCpuBudget, @function\n"
    ".symver sceSystemServiceReleaseBgmCpuBudget, sceSystemServiceReleaseBgmCpuBudget@@0x317F56880277E815\n"
    "sceSystemServiceReleaseBgmCpuBudget:\n");

asm(".global sceSystemServiceReleaseFb0\n"
    ".type   sceSystemServiceReleaseFb0, @function\n"
    ".symver sceSystemServiceReleaseFb0, sceSystemServiceReleaseFb0@@0x3A6B34EB9A880A56\n"
    "sceSystemServiceReleaseFb0:\n");

asm(".global sceSystemServiceReportAbnormalTermination\n"
    ".type   sceSystemServiceReportAbnormalTermination, @function\n"
    ".symver sceSystemServiceReportAbnormalTermination, sceSystemServiceReportAbnormalTermination@@0xDECF1C1E20812811\n"
    "sceSystemServiceReportAbnormalTermination:\n");

asm(".global sceSystemServiceRequestCameraCalibration\n"
    ".type   sceSystemServiceRequestCameraCalibration, @function\n"
    ".symver sceSystemServiceRequestCameraCalibration, sceSystemServiceRequestCameraCalibration@@0xDD9169CDC46A62C9\n"
    "sceSystemServiceRequestCameraCalibration:\n");

asm(".global sceSystemServiceRequestPowerOff\n"
    ".type   sceSystemServiceRequestPowerOff, @function\n"
    ".symver sceSystemServiceRequestPowerOff, sceSystemServiceRequestPowerOff@@0x7788A6CAE9C7AF2A\n"
    "sceSystemServiceRequestPowerOff:\n");

asm(".global sceSystemServiceRequestReboot\n"
    ".type   sceSystemServiceRequestReboot, @function\n"
    ".symver sceSystemServiceRequestReboot, sceSystemServiceRequestReboot@@0xA0426A1AC36D148C\n"
    "sceSystemServiceRequestReboot:\n");

asm(".global sceSystemServiceRequestToChangeRenderingMode\n"
    ".type   sceSystemServiceRequestToChangeRenderingMode, @function\n"
    ".symver sceSystemServiceRequestToChangeRenderingMode, sceSystemServiceRequestToChangeRenderingMode@@0x3FBD5FBE71F21534\n"
    "sceSystemServiceRequestToChangeRenderingMode:\n");

asm(".global sceSystemServiceResumeLocalProcess\n"
    ".type   sceSystemServiceResumeLocalProcess, @function\n"
    ".symver sceSystemServiceResumeLocalProcess, sceSystemServiceResumeLocalProcess@@0xB4CBB3B9971421C0\n"
    "sceSystemServiceResumeLocalProcess:\n");

asm(".global sceSystemServiceSaveVideoToken\n"
    ".type   sceSystemServiceSaveVideoToken, @function\n"
    ".symver sceSystemServiceSaveVideoToken, sceSystemServiceSaveVideoToken@@0x0C82EECDCBD78C64\n"
    "sceSystemServiceSaveVideoToken:\n");

asm(".global sceSystemServiceSetControllerFocusPermission\n"
    ".type   sceSystemServiceSetControllerFocusPermission, @function\n"
    ".symver sceSystemServiceSetControllerFocusPermission, sceSystemServiceSetControllerFocusPermission@@0x0CD13BEEC7CDC396\n"
    "sceSystemServiceSetControllerFocusPermission:\n");

asm(".global sceSystemServiceSetGpuLoadEmulationMode\n"
    ".type   sceSystemServiceSetGpuLoadEmulationMode, @function\n"
    ".symver sceSystemServiceSetGpuLoadEmulationMode, sceSystemServiceSetGpuLoadEmulationMode@@0x78B5A73EE8DAF98F\n"
    "sceSystemServiceSetGpuLoadEmulationMode:\n");

asm(".global sceSystemServiceSetNoticeScreenSkipFlag\n"
    ".type   sceSystemServiceSetNoticeScreenSkipFlag, @function\n"
    ".symver sceSystemServiceSetNoticeScreenSkipFlag, sceSystemServiceSetNoticeScreenSkipFlag@@0x437BAD26F99AE0CA\n"
    "sceSystemServiceSetNoticeScreenSkipFlag:\n");

asm(".global sceSystemServiceSetOutOfVrPlayAreaFlag\n"
    ".type   sceSystemServiceSetOutOfVrPlayAreaFlag, @function\n"
    ".symver sceSystemServiceSetOutOfVrPlayAreaFlag, sceSystemServiceSetOutOfVrPlayAreaFlag@@0x0000000000000000\n"
    "sceSystemServiceSetOutOfVrPlayAreaFlag:\n");

asm(".global sceSystemServiceSetOutOfVrPlayZoneWarning\n"
    ".type   sceSystemServiceSetOutOfVrPlayZoneWarning, @function\n"
    ".symver sceSystemServiceSetOutOfVrPlayZoneWarning, sceSystemServiceSetOutOfVrPlayZoneWarning@@0xB2044F3498EB5A38\n"
    "sceSystemServiceSetOutOfVrPlayZoneWarning:\n");

asm(".global sceSystemServiceSetPowerSaveLevel\n"
    ".type   sceSystemServiceSetPowerSaveLevel, @function\n"
    ".symver sceSystemServiceSetPowerSaveLevel, sceSystemServiceSetPowerSaveLevel@@0x0000000000000000\n"
    "sceSystemServiceSetPowerSaveLevel:\n");

asm(".global sceSystemServiceShowClosedCaptionAdvancedSettings\n"
    ".type   sceSystemServiceShowClosedCaptionAdvancedSettings, @function\n"
    ".symver sceSystemServiceShowClosedCaptionAdvancedSettings, sceSystemServiceShowClosedCaptionAdvancedSettings@@0xBA10FB83BCD7210A\n"
    "sceSystemServiceShowClosedCaptionAdvancedSettings:\n");

asm(".global sceSystemServiceShowClosedCaptionSettings\n"
    ".type   sceSystemServiceShowClosedCaptionSettings, @function\n"
    ".symver sceSystemServiceShowClosedCaptionSettings, sceSystemServiceShowClosedCaptionSettings@@0xE56E8BBABCCC65A6\n"
    "sceSystemServiceShowClosedCaptionSettings:\n");

asm(".global sceSystemServiceShowControllerSettings\n"
    ".type   sceSystemServiceShowControllerSettings, @function\n"
    ".symver sceSystemServiceShowControllerSettings, sceSystemServiceShowControllerSettings@@0xC3DC2529C1EB9A6F\n"
    "sceSystemServiceShowControllerSettings:\n");

asm(".global sceSystemServiceShowDisplaySafeAreaSettings\n"
    ".type   sceSystemServiceShowDisplaySafeAreaSettings, @function\n"
    ".symver sceSystemServiceShowDisplaySafeAreaSettings, sceSystemServiceShowDisplaySafeAreaSettings@@0x00B4F7D0536A43E0\n"
    "sceSystemServiceShowDisplaySafeAreaSettings:\n");

asm(".global sceSystemServiceShowErrorDialog\n"
    ".type   sceSystemServiceShowErrorDialog, @function\n"
    ".symver sceSystemServiceShowErrorDialog, sceSystemServiceShowErrorDialog@@0xF1043139940FF657\n"
    "sceSystemServiceShowErrorDialog:\n");

asm(".global sceSystemServiceShowEyeToEyeDistanceSetting\n"
    ".type   sceSystemServiceShowEyeToEyeDistanceSetting, @function\n"
    ".symver sceSystemServiceShowEyeToEyeDistanceSetting, sceSystemServiceShowEyeToEyeDistanceSetting@@0x7FC799BC9F2157AA\n"
    "sceSystemServiceShowEyeToEyeDistanceSetting:\n");

asm(".global sceSystemServiceShowImposeMenuForPs2Emu\n"
    ".type   sceSystemServiceShowImposeMenuForPs2Emu, @function\n"
    ".symver sceSystemServiceShowImposeMenuForPs2Emu, sceSystemServiceShowImposeMenuForPs2Emu@@0x62D0E4ED7DC5174F\n"
    "sceSystemServiceShowImposeMenuForPs2Emu:\n");

asm(".global sceSystemServiceSuspendBackgroundApp\n"
    ".type   sceSystemServiceSuspendBackgroundApp, @function\n"
    ".symver sceSystemServiceSuspendBackgroundApp, sceSystemServiceSuspendBackgroundApp@@0x00BD8D5166DBEF6E\n"
    "sceSystemServiceSuspendBackgroundApp:\n");

asm(".global sceSystemServiceSuspendLocalProcess\n"
    ".type   sceSystemServiceSuspendLocalProcess, @function\n"
    ".symver sceSystemServiceSuspendLocalProcess, sceSystemServiceSuspendLocalProcess@@0x913880C7B7B6CD4E\n"
    "sceSystemServiceSuspendLocalProcess:\n");

asm(".global sceSystemServiceTelemetrySetData\n"
    ".type   sceSystemServiceTelemetrySetData, @function\n"
    ".symver sceSystemServiceTelemetrySetData, sceSystemServiceTelemetrySetData@@0xDE79FBAE739DB758\n"
    "sceSystemServiceTelemetrySetData:\n");

asm(".global sceSystemServiceTelemetrySetData2\n"
    ".type   sceSystemServiceTelemetrySetData2, @function\n"
    ".symver sceSystemServiceTelemetrySetData2, sceSystemServiceTelemetrySetData2@@0xF3795E666B26993E\n"
    "sceSystemServiceTelemetrySetData2:\n");

asm(".global sceSystemServiceTickVideoPlayback\n"
    ".type   sceSystemServiceTickVideoPlayback, @function\n"
    ".symver sceSystemServiceTickVideoPlayback, sceSystemServiceTickVideoPlayback@@0x00CE55EA9333D876\n"
    "sceSystemServiceTickVideoPlayback:\n");

asm(".global sceSystemServiceTurnOffScreenSaver\n"
    ".type   sceSystemServiceTurnOffScreenSaver, @function\n"
    ".symver sceSystemServiceTurnOffScreenSaver, sceSystemServiceTurnOffScreenSaver@@0x00BCE86ACC83225B\n"
    "sceSystemServiceTurnOffScreenSaver:\n");

asm(".global sceSystemServiceUsbStorageGetDeviceInfo\n"
    ".type   sceSystemServiceUsbStorageGetDeviceInfo, @function\n"
    ".symver sceSystemServiceUsbStorageGetDeviceInfo, sceSystemServiceUsbStorageGetDeviceInfo@@0x2D4829A1D351EB53\n"
    "sceSystemServiceUsbStorageGetDeviceInfo:\n");

asm(".global sceSystemServiceUsbStorageGetDeviceList\n"
    ".type   sceSystemServiceUsbStorageGetDeviceList, @function\n"
    ".symver sceSystemServiceUsbStorageGetDeviceList, sceSystemServiceUsbStorageGetDeviceList@@0x00A7BF5911DF2A5B\n"
    "sceSystemServiceUsbStorageGetDeviceList:\n");

asm(".global sceSystemServiceUsbStorageGetdentsClose\n"
    ".type   sceSystemServiceUsbStorageGetdentsClose, @function\n"
    ".symver sceSystemServiceUsbStorageGetdentsClose, sceSystemServiceUsbStorageGetdentsClose@@0x795A444D9CCC467D\n"
    "sceSystemServiceUsbStorageGetdentsClose:\n");

asm(".global sceSystemServiceUsbStorageGetdentsOpen\n"
    ".type   sceSystemServiceUsbStorageGetdentsOpen, @function\n"
    ".symver sceSystemServiceUsbStorageGetdentsOpen, sceSystemServiceUsbStorageGetdentsOpen@@0x705AD4BC2694E4A1\n"
    "sceSystemServiceUsbStorageGetdentsOpen:\n");

asm(".global sceSystemServiceUsbStorageGetdentsRead\n"
    ".type   sceSystemServiceUsbStorageGetdentsRead, @function\n"
    ".symver sceSystemServiceUsbStorageGetdentsRead, sceSystemServiceUsbStorageGetdentsRead@@0x2FB5E0EB17419E24\n"
    "sceSystemServiceUsbStorageGetdentsRead:\n");

asm(".global sceSystemServiceUsbStorageInit\n"
    ".type   sceSystemServiceUsbStorageInit, @function\n"
    ".symver sceSystemServiceUsbStorageInit, sceSystemServiceUsbStorageInit@@0xBEFF67D78BD0B66A\n"
    "sceSystemServiceUsbStorageInit:\n");

asm(".global sceSystemServiceUsbStorageIsExist\n"
    ".type   sceSystemServiceUsbStorageIsExist, @function\n"
    ".symver sceSystemServiceUsbStorageIsExist, sceSystemServiceUsbStorageIsExist@@0x0BE3F99D4C3B1581\n"
    "sceSystemServiceUsbStorageIsExist:\n");

asm(".global sceSystemServiceUsbStorageRegisterCallback\n"
    ".type   sceSystemServiceUsbStorageRegisterCallback, @function\n"
    ".symver sceSystemServiceUsbStorageRegisterCallback, sceSystemServiceUsbStorageRegisterCallback@@0xAE7BC35A70223363\n"
    "sceSystemServiceUsbStorageRegisterCallback:\n");

asm(".global sceSystemServiceUsbStorageRegisterCallbackForMapAvailable\n"
    ".type   sceSystemServiceUsbStorageRegisterCallbackForMapAvailable, @function\n"
    ".symver sceSystemServiceUsbStorageRegisterCallbackForMapAvailable, sceSystemServiceUsbStorageRegisterCallbackForMapAvailable@@0x96DEDE36E5E9C3C4\n"
    "sceSystemServiceUsbStorageRegisterCallbackForMapAvailable:\n");

asm(".global sceSystemServiceUsbStorageRegisterCallbackForMapUnavailable\n"
    ".type   sceSystemServiceUsbStorageRegisterCallbackForMapUnavailable, @function\n"
    ".symver sceSystemServiceUsbStorageRegisterCallbackForMapUnavailable, sceSystemServiceUsbStorageRegisterCallbackForMapUnavailable@@0x003340A958DCD5D6\n"
    "sceSystemServiceUsbStorageRegisterCallbackForMapUnavailable:\n");

asm(".global sceSystemServiceUsbStorageRequestMap\n"
    ".type   sceSystemServiceUsbStorageRequestMap, @function\n"
    ".symver sceSystemServiceUsbStorageRequestMap, sceSystemServiceUsbStorageRequestMap@@0x5D3575C6FDC7E2AC\n"
    "sceSystemServiceUsbStorageRequestMap:\n");

asm(".global sceSystemServiceUsbStorageRequestMapWSB\n"
    ".type   sceSystemServiceUsbStorageRequestMapWSB, @function\n"
    ".symver sceSystemServiceUsbStorageRequestMapWSB, sceSystemServiceUsbStorageRequestMapWSB@@0xA471F98727F15FD6\n"
    "sceSystemServiceUsbStorageRequestMapWSB:\n");

asm(".global sceSystemServiceUsbStorageRequestUnmap\n"
    ".type   sceSystemServiceUsbStorageRequestUnmap, @function\n"
    ".symver sceSystemServiceUsbStorageRequestUnmap, sceSystemServiceUsbStorageRequestUnmap@@0xB3CBEE1DBBDBB62B\n"
    "sceSystemServiceUsbStorageRequestUnmap:\n");

asm(".global sceSystemServiceUsbStorageTerm\n"
    ".type   sceSystemServiceUsbStorageTerm, @function\n"
    ".symver sceSystemServiceUsbStorageTerm, sceSystemServiceUsbStorageTerm@@0x8D0710800D0627A9\n"
    "sceSystemServiceUsbStorageTerm:\n");

asm(".global sceSystemServiceUsbStorageUnregisterCallback\n"
    ".type   sceSystemServiceUsbStorageUnregisterCallback, @function\n"
    ".symver sceSystemServiceUsbStorageUnregisterCallback, sceSystemServiceUsbStorageUnregisterCallback@@0x72F4E75500664590\n"
    "sceSystemServiceUsbStorageUnregisterCallback:\n");

asm(".global sceSystemServiceUsbStorageUnregisterCallbackForMapAvailable\n"
    ".type   sceSystemServiceUsbStorageUnregisterCallbackForMapAvailable, @function\n"
    ".symver sceSystemServiceUsbStorageUnregisterCallbackForMapAvailable, sceSystemServiceUsbStorageUnregisterCallbackForMapAvailable@@0xE3015D86F18E9479\n"
    "sceSystemServiceUsbStorageUnregisterCallbackForMapAvailable:\n");

asm(".global sceSystemServiceUsbStorageUnregisterCallbackForMapUnavailable\n"
    ".type   sceSystemServiceUsbStorageUnregisterCallbackForMapUnavailable, @function\n"
    ".symver sceSystemServiceUsbStorageUnregisterCallbackForMapUnavailable, sceSystemServiceUsbStorageUnregisterCallbackForMapUnavailable@@0x008D460A86F4F496\n"
    "sceSystemServiceUsbStorageUnregisterCallbackForMapUnavailable:\n");

asm(".global sceSystemStateMgrCancelShutdownTimer\n"
    ".type   sceSystemStateMgrCancelShutdownTimer, @function\n"
    ".symver sceSystemStateMgrCancelShutdownTimer, sceSystemStateMgrCancelShutdownTimer@@0x7811730D84E1ADAB\n"
    "sceSystemStateMgrCancelShutdownTimer:\n");

asm(".global sceSystemStateMgrEnterMediaPlaybackMode\n"
    ".type   sceSystemStateMgrEnterMediaPlaybackMode, @function\n"
    ".symver sceSystemStateMgrEnterMediaPlaybackMode, sceSystemStateMgrEnterMediaPlaybackMode@@0x029E5D274CC74556\n"
    "sceSystemStateMgrEnterMediaPlaybackMode:\n");

asm(".global sceSystemStateMgrEnterStandby\n"
    ".type   sceSystemStateMgrEnterStandby, @function\n"
    ".symver sceSystemStateMgrEnterStandby, sceSystemStateMgrEnterStandby@@0x2DA69CD12E05BA11\n"
    "sceSystemStateMgrEnterStandby:\n");

asm(".global sceSystemStateMgrExtendShutdownTimer\n"
    ".type   sceSystemStateMgrExtendShutdownTimer, @function\n"
    ".symver sceSystemStateMgrExtendShutdownTimer, sceSystemStateMgrExtendShutdownTimer@@0xAD2AAEBCEB704269\n"
    "sceSystemStateMgrExtendShutdownTimer:\n");

asm(".global sceSystemStateMgrExtendShutdownTimerForPostAutoUpdateProcess\n"
    ".type   sceSystemStateMgrExtendShutdownTimerForPostAutoUpdateProcess, @function\n"
    ".symver sceSystemStateMgrExtendShutdownTimerForPostAutoUpdateProcess, sceSystemStateMgrExtendShutdownTimerForPostAutoUpdateProcess@@0x1738C848C5B0E578\n"
    "sceSystemStateMgrExtendShutdownTimerForPostAutoUpdateProcess:\n");

asm(".global sceSystemStateMgrGetCurrentState\n"
    ".type   sceSystemStateMgrGetCurrentState, @function\n"
    ".symver sceSystemStateMgrGetCurrentState, sceSystemStateMgrGetCurrentState@@0xCDED24CB9435C84F\n"
    "sceSystemStateMgrGetCurrentState:\n");

asm(".global sceSystemStateMgrGetTriggerCode\n"
    ".type   sceSystemStateMgrGetTriggerCode, @function\n"
    ".symver sceSystemStateMgrGetTriggerCode, sceSystemStateMgrGetTriggerCode@@0xC25C6F1124D4A659\n"
    "sceSystemStateMgrGetTriggerCode:\n");

asm(".global sceSystemStateMgrIsBdDriveReady\n"
    ".type   sceSystemStateMgrIsBdDriveReady, @function\n"
    ".symver sceSystemStateMgrIsBdDriveReady, sceSystemStateMgrIsBdDriveReady@@0x7268EE62956E8D0B\n"
    "sceSystemStateMgrIsBdDriveReady:\n");

asm(".global sceSystemStateMgrIsGpuPerformanceNormal\n"
    ".type   sceSystemStateMgrIsGpuPerformanceNormal, @function\n"
    ".symver sceSystemStateMgrIsGpuPerformanceNormal, sceSystemStateMgrIsGpuPerformanceNormal@@0xB5EC4B3CB0D70ECA\n"
    "sceSystemStateMgrIsGpuPerformanceNormal:\n");

asm(".global sceSystemStateMgrIsShellUIShutdownInProgress\n"
    ".type   sceSystemStateMgrIsShellUIShutdownInProgress, @function\n"
    ".symver sceSystemStateMgrIsShellUIShutdownInProgress, sceSystemStateMgrIsShellUIShutdownInProgress@@0x6AC2C17B47AC9886\n"
    "sceSystemStateMgrIsShellUIShutdownInProgress:\n");

asm(".global sceSystemStateMgrIsStandbyModeEnabled\n"
    ".type   sceSystemStateMgrIsStandbyModeEnabled, @function\n"
    ".symver sceSystemStateMgrIsStandbyModeEnabled, sceSystemStateMgrIsStandbyModeEnabled@@0x8F722B3822FE0E63\n"
    "sceSystemStateMgrIsStandbyModeEnabled:\n");

asm(".global sceSystemStateMgrLeaveMediaPlaybackMode\n"
    ".type   sceSystemStateMgrLeaveMediaPlaybackMode, @function\n"
    ".symver sceSystemStateMgrLeaveMediaPlaybackMode, sceSystemStateMgrLeaveMediaPlaybackMode@@0xF3CCB90F3B655C11\n"
    "sceSystemStateMgrLeaveMediaPlaybackMode:\n");

asm(".global sceSystemStateMgrNotifySystemSuspendResumeProgress\n"
    ".type   sceSystemStateMgrNotifySystemSuspendResumeProgress, @function\n"
    ".symver sceSystemStateMgrNotifySystemSuspendResumeProgress, sceSystemStateMgrNotifySystemSuspendResumeProgress@@0x1F67FA67022A2C98\n"
    "sceSystemStateMgrNotifySystemSuspendResumeProgress:\n");

asm(".global sceSystemStateMgrReboot\n"
    ".type   sceSystemStateMgrReboot, @function\n"
    ".symver sceSystemStateMgrReboot, sceSystemStateMgrReboot@@0xB91D701475D7D574\n"
    "sceSystemStateMgrReboot:\n");

asm(".global sceSystemStateMgrRequestToKeepMainOnStandby\n"
    ".type   sceSystemStateMgrRequestToKeepMainOnStandby, @function\n"
    ".symver sceSystemStateMgrRequestToKeepMainOnStandby, sceSystemStateMgrRequestToKeepMainOnStandby@@0xF56447935C104F4F\n"
    "sceSystemStateMgrRequestToKeepMainOnStandby:\n");

asm(".global sceSystemStateMgrSendCecOneTouchPlayCommand\n"
    ".type   sceSystemStateMgrSendCecOneTouchPlayCommand, @function\n"
    ".symver sceSystemStateMgrSendCecOneTouchPlayCommand, sceSystemStateMgrSendCecOneTouchPlayCommand@@0x80FC756F7EB3C8C6\n"
    "sceSystemStateMgrSendCecOneTouchPlayCommand:\n");

asm(".global sceSystemStateMgrStartRebootTimer\n"
    ".type   sceSystemStateMgrStartRebootTimer, @function\n"
    ".symver sceSystemStateMgrStartRebootTimer, sceSystemStateMgrStartRebootTimer@@0x3DC2790CBCD95D2B\n"
    "sceSystemStateMgrStartRebootTimer:\n");

asm(".global sceSystemStateMgrStartShutdownTimer\n"
    ".type   sceSystemStateMgrStartShutdownTimer, @function\n"
    ".symver sceSystemStateMgrStartShutdownTimer, sceSystemStateMgrStartShutdownTimer@@0xEEA7FB9A1CCE40FA\n"
    "sceSystemStateMgrStartShutdownTimer:\n");

asm(".global sceSystemStateMgrStartStadbyTimer\n"
    ".type   sceSystemStateMgrStartStadbyTimer, @function\n"
    ".symver sceSystemStateMgrStartStadbyTimer, sceSystemStateMgrStartStadbyTimer@@0x6708504874EA1A91\n"
    "sceSystemStateMgrStartStadbyTimer:\n");

asm(".global sceSystemStateMgrStartVshAutoUpdateTimer\n"
    ".type   sceSystemStateMgrStartVshAutoUpdateTimer, @function\n"
    ".symver sceSystemStateMgrStartVshAutoUpdateTimer, sceSystemStateMgrStartVshAutoUpdateTimer@@0x6167ED06AE7485C0\n"
    "sceSystemStateMgrStartVshAutoUpdateTimer:\n");

asm(".global sceSystemStateMgrTickMusicPlayback\n"
    ".type   sceSystemStateMgrTickMusicPlayback, @function\n"
    ".symver sceSystemStateMgrTickMusicPlayback, sceSystemStateMgrTickMusicPlayback@@0x00CA9941A1964A38\n"
    "sceSystemStateMgrTickMusicPlayback:\n");

asm(".global sceSystemStateMgrTickPartyChat\n"
    ".type   sceSystemStateMgrTickPartyChat, @function\n"
    ".symver sceSystemStateMgrTickPartyChat, sceSystemStateMgrTickPartyChat@@0x1AFA8FB0F5F81142\n"
    "sceSystemStateMgrTickPartyChat:\n");

asm(".global sceSystemStateMgrTurnOff\n"
    ".type   sceSystemStateMgrTurnOff, @function\n"
    ".symver sceSystemStateMgrTurnOff, sceSystemStateMgrTurnOff@@0x80ADC45FA64AB4A7\n"
    "sceSystemStateMgrTurnOff:\n");

asm(".global sceSystemStateMgrVshAutoUpdate\n"
    ".type   sceSystemStateMgrVshAutoUpdate, @function\n"
    ".symver sceSystemStateMgrVshAutoUpdate, sceSystemStateMgrVshAutoUpdate@@0x5357595C08E4055A\n"
    "sceSystemStateMgrVshAutoUpdate:\n");

asm(".global sceSystemStateMgrWaitVshAutoUpdateVerifyDone\n"
    ".type   sceSystemStateMgrWaitVshAutoUpdateVerifyDone, @function\n"
    ".symver sceSystemStateMgrWaitVshAutoUpdateVerifyDone, sceSystemStateMgrWaitVshAutoUpdateVerifyDone@@0x81E836EA578EB2FC\n"
    "sceSystemStateMgrWaitVshAutoUpdateVerifyDone:\n");

asm(".global sceSystemStateMgrWakeUp\n"
    ".type   sceSystemStateMgrWakeUp, @function\n"
    ".symver sceSystemStateMgrWakeUp, sceSystemStateMgrWakeUp@@0xEA0B6A2CF5537496\n"
    "sceSystemStateMgrWakeUp:\n");
