// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

// 학생 데이터를 관리할 구조체 선언.
USTRUCT()
struct FStudentData
{
	GENERATED_BODY()

	FStudentData()
	{
		Name = TEXT("홍길동");
		Order = -1;
	}

	FStudentData(const FString& InName, int32 InOrder)
		: Name(InName), Order(InOrder)
	{
	}

	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Order;
};

/**
 * 
 */
UCLASS()
class UEPART1_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	// 생성자.
	UMyGameInstance();

private:
	// 게임 인스턴스 초기화 함수.
	virtual void Init() override;

private:
	// 학생 데이터를 배열로 관리.
	TArray<FStudentData> StudentsData;

	// TArray로 UObject 타입을 관리할 때는 UPROPERTY() 매크로 필수.
	UPROPERTY()
	TArray<TObjectPtr<class UStudent>> Students;
};
