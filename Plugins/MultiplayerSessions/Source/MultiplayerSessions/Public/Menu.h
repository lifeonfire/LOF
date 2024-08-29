// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

class UButton;
class UScrollBox;
class UEditableText;
class UServerRow;
class UCircularThrobber;
class UOverlay;

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	/** Constructor */
	UMenu(const FObjectInitializer& ObjectInitializer);

	/** Called from level blueprint in BeginPlay to add this menu to viewport */
	UFUNCTION(BlueprintCallable)
		void MenuSetup(int32 NumberOfPublicConnections = 2, FString TypeOfMatch = FString(TEXT("FreeForAll")), FString LobbyPath = FString(TEXT("/Game/ThirdPersonCPP/Maps/Lobby")));

	/** Called by UServerRow::JoinBClicked(), when you click on the server you want to join */
	void ServerJoinButtonClciked(const FOnlineSessionSearchResult& Result);

protected:

	/** BeginPlay Native Event */
	virtual bool Initialize() override;


	virtual void NativeConstruct() override;

	/** Destroyed Native Event */
	virtual void NativeDestruct() override;

	/** Callbacks for the custom delegates on the MultiplayerSessionsSubsystem */
	UFUNCTION()
		void OnCreateSession(bool bWasSuccessful);
	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
		void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
		void OnStartSession(bool bWasSuccessful);

	/** This button hosts the session as per player data */
	UPROPERTY(meta = (BindWidget))
		UButton* HostSessionButton = nullptr;

	/** Ends the game */
	UPROPERTY(meta = (BindWidget))
		UButton* JoinRandomSessionButton = nullptr;

	/** Ends the game */
	UPROPERTY(meta = (BindWidget))
		UButton* QuitButton = nullptr;

	UPROPERTY(meta = (BindWidget))
		UScrollBox* ServerList = nullptr;

	UPROPERTY(meta = (BindWidget))
		UEditableText* ServerNameBox = nullptr;

	UPROPERTY(meta = (BindWidget))
		UCircularThrobber* SearchingThrobber = nullptr;

	UPROPERTY(meta = (BindWidget))
		UOverlay* JoiningSessionOverlay = nullptr;

	static TSubclassOf<UUserWidget> ServerRowClass;

	UServerRow* ServerRow = nullptr;

	UPROPERTY(BlueprintReadWrite)
		int32 NumPublicConnections = 2;

private:

	FTimerHandle RefreshSessionsList;

	UFUNCTION()
		void HostSessionButtonClicked();

	UFUNCTION()
		void QuitButtonClicked();	

	UFUNCTION()
		void JoinRandomSessionButtonClicked();
	
	void RefreshActiveSessionsList();

	void MenuTearDown();

	void SetServerList(const FOnlineSessionSearchResult& Result);

	// The subsystem designed to handle all online session functionality
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	FString MatchType = TEXT("FreeForAll");
	
	FString PathToLobby = TEXT("");
};
