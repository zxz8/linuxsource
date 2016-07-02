//Data struct type begin
enum EmDataType
{
  emAtomTypeBegin =0,//ԭ����������
	em_BOOL,
	em_u8,
	em_s8,
	em_u16,
	em_u32,
	em_u32_ip,
	em_string,
  emEnumTypeBegin,//ö����������
	em_EmWiFiLinkStat,
	em_EmWiFiSelType,
	em_EmWiFiNetType,
	em_EmWiFiEncryptType,
	em_EmWiFiEncryptArithmetic,
	em_EmVODRejCode,
	em_EmVODState,
	em_EmTextAlign,
	em_EmRollMode,
	em_EmRollSpeed,
	em_EmStopBits,
	em_EmParityCheck,
	em_EmSerialType,
	em_EmLanguage,
	em_EmConfProtocol,
	em_EmEncodeMode,
	em_EmLostPackageRestore,
	em_EmMatrixType,
	em_EmDualVideoShowMode,
	em_EmDisplayRatio,
	em_EmVideoType,
	em_EmVideoStandard,
	em_EmVideoInterface,
	em_EmMtVideoPort,
	em_EmTripMode,
	em_EmLabelType,
	em_EmDLProtocol,
	em_EmAuthenticationType,
	em_EmFrameUnitType,
	em_EmMediaType,
	em_EmVideoFormat,
	em_EmAudioFormat,
	em_EmVideoResolution,
	em_EmQoS,
	em_EmTOS,
	em_EmSite,
	em_EmChanType,
	em_EmCodecComponent,
	em_EmMtModel,
	em_EmFileSys,
	em_EmEncryptArithmetic,
	em_EmAction,
	em_EmOptRet,
	em_EmConfMode,
	em_EmMtAddrType,
	em_EmCallMode,
	em_EmDirection,
	em_EmCallState,
	em_EmCallSiteState,
	em_EmTransMode,
	em_EmDualSrcType,
	em_EmMtInstType,
	em_EmVMPStyle,
	em_EmVMPMmbType,
	em_EmSMSType,
	em_EmMtFile,
	em_EmCallRate,
	em_EmPCCapFormat,
	em_EmPiPMode,
	em_EmDVBComponent,
	em_EmUIPosion,
	em_EmCallDisconnectReason,
	em_EmMCMode,
	em_EmInnerVMPStyle,
	em_EmVMPComponent,
	em_EmCapType,
	em_EmPPPoEState,
	em_EmDhcpState,
	em_EmAddrGroupOptType,
	em_EmHotKeyType,
	em_EmMtOSType,
	em_EmFxoState,
	em_EmMtLoudspeakerVal,
	em_EmNetType,
	em_EmSysRunSuccessFlag,
	em_EmMcuNtfMsgType,
	em_EmAutoTestType,
	em_EmGKRegFailedReason,
	em_HD_PORT_MASK,
	em_EmHDAudPort,
  emStructTypeBegin,//���ݽṹ��������
	em_TH323Cfg,
	em_TGuideCfg,
	em_TSymboPoint,
	em_TOsdCfg,
	em_TMtKdvTime,
	em_TUserCfg,
	em_TVgaOutCfg,
	em_TMtEquipmentCapset,
	em_TInnerMcCfg,
	em_TEthnetInfo,
	em_TE1Unit,
	em_TE1Config,
	em_TSerialCfg,
	em_TRouteCfg,
	em_TPPPOECfg,
	em_TPPPoEStates,
	em_TPPPoEAuthFailed,
	em_TPPPoEConnNotify,
	em_TPPPoENoServer,
	em_TPPPoEVersion,
	em_TSNMPCfg,
	em_TIPQoS,
	em_TStreamMedia,
	em_TVideoParam,
	em_TAVPriorStrategy,
	em_TLostPackResend,
	em_TCameraTypeInfo,
	em_TCameraCfg,
	em_TVideoStandard,
	em_TVideoSource,
	em_TSnapInfo,
	em_TBannerInfo,
	em_TCodecStatistic,
	em_TAudioPower,
	em_TMtId,
	em_TConfBaseInfo,
	em_TConfListInfo,
	em_TMtInfo,
	em_TMtVideoCodecStatus,
	em_TTerStatus,
	em_TMtVMPParam,
	em_TMtVmpItem,
	em_TMtPollInfo,
	em_TMtSimpConfInfo,
	em_TMtConfInfo,
	em_TMtCodecStat,
	em_TIPTransAddr,
	em_TMtAddr,
	em_TConfId,
	em_TDialParam,
	em_TLinkState,
	em_TEmbedFwNatProxy,
	em_TNATMapAddr,
	em_TGKCfg,
	em_TInnerGKCfg,
	em_TInnerProxyCfg,
	em_TWiFiNetCfg,
	em_TMonitorService,
	em_TRect,
	em_TPoint,
	em_TDualStream,
	em_TDualRation,
	em_TImageAdjustParam,
	em_TVideoEncodeParameter,
	em_TEncryptKey,
	em_TVideoChanParam,
	em_TAudioChanParam,
	em_TVODUserInfo,
	em_TVODFile,
	em_TVODFileNameInfo,
	em_TVODFileInfo,
	em_TRequestPalyInfo,
	em_TVideoSourceInfo,
	em_TExternalMatrixInfo,
	em_TAVInnerMatrixScheme,
	em_TMtSMS,
	em_TUserCfgNotify,
	em_TNetConfigNotify,
	em_TAVConfigNotify,
	em_TBitRateAdjust,
	em_TCodecPackStat,
	em_TVideoStatistics,
	em_TAudioStatistics,
	em_TCapType,
	em_TCallInfoStatistics,
	em_TDualStreamBoxInfo,
	em_TFileTransfer,
	em_TDVBNetSession,
	em_TDVBNetSndParam,
	em_TDVBLocalNetParam,
	em_TDVBVideoEncParam,
	em_TSitecallInformation,
	em_TTransparentSerial,
	em_TPeerCapabilityInfo,
	em_TRapidKey,
	em_TVerFileInfo,
	em_TVerInfo,
	em_TFecInfo,
	em_THDAVInnerMatrixScheme,
	em_TMtAutoTestMsg,
	em_TAddrEntry,
	em_TPxyIPCfg,
	em_TWifiLinkInfo,
	em_TWifiScanResult,
	em_TWifiLinkCfgItem,
	em_TWifiCfgInfo,
	em_TWifiLinkStat,
	em_TWiFiBSSIDInfo,
	em_TWiFiBSSIDCfg,
	em_TGkRegInfo,
	em_TSiteCallResult,
	em_THdAudioPort,
	em_TMiscCfg,
	em_TVideoDisplayFrm,
emDataTypeEnd //���Ͷ������
};