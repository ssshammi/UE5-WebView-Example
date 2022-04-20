// Fill out your copyright notice in the Description page of Project Settings.


#include "WebLink.h"
#include "Dom/JsonObject.h"

void UWebLink::AvatarGenerated(FString jsonResponse) {
	FString url = "";
	if (jsonResponse.Contains(TEXT(".glb"))) {
		UE_LOG(LogTemp, Warning, TEXT(".glb found "));
		url = jsonResponse;
	}
	if (url.IsEmpty()) {
		return;
	}

	UWebLink::WebBrowserResponse.Execute(url);
	lastAvatarUrl = url;
}

void UWebLink::SetAvatarUrlCallback(FReadyPlayerWebBrowserResponse webBrowserCallback)
{
	UWebLink::WebBrowserResponse = webBrowserCallback;
}

FString UWebLink::GetLastAvatarUrl()
{
	return UWebLink::lastAvatarUrl;
}

