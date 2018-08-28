
- When you initialise the SDK, please do as always:

    TagCommander *tc = [[TagCommander alloc] initWithSiteID: siteID andContainerID: containerID];
    [tc enableSDK];

- But then, add:
    [[TCPartner_Mediametrie sharedInstance] setPartnerID: 225025218272];


- Later when you launch a video, please start by calling:
[[TCPartner_Mediametrie sharedInstance] startSession];


- Then you need to send a regular hit every 10 seconds with "ESTAT_VIDEO" inside the parameters so that the SDK can sort them and send them only when we really started the session.


- And when the video is over:
[[TCPartner_Mediametrie sharedInstance] stopSession];
