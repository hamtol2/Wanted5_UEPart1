// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

UMyGameInstance::UMyGameInstance()
{
	// 기본값 설정.
	// 생성자에서 설정하는 기본 값은 CDO 템플릿 객체에 저장됨.
	SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("======================="));
	TArray<UPerson*> Persons =
	{
		NewObject<UStudent>(),
		NewObject<UTeacher>(),
		NewObject<UStaff>(),
	};

	// 범위 기반 루프 활용 이름 출력.
	for (const auto Person : Persons)
	{
		UE_LOG(
			LogTemp,
			Log,
			TEXT("구성원 이름: %s"),
			*Person->GetName()
		);
	}

	// 인터페이스 구현 여부에 따른 수업 참여 구분.
	// 구현 여부를 확인하는 방법? -> 해당 인터페이스로 형변환(다운 캐스팅).
	// 다운 캐스팅.RTTI.
	for (const auto Person : Persons)
	{
		// 형변환을 통한 인터페이스 구현 여부 확인.
		ILessonInterface* LessonInterface
			= Cast<ILessonInterface>(Person);

		// 형변환에 성공했다면 구현한 경우.
		if (LessonInterface)
		{
			UE_LOG(
				LogTemp,
				Log,
				TEXT("%s님은 수업에 참여할 수 있습니다."),
				*Person->GetName()
			);
			LessonInterface->DoLesson();
		}
		// 형변환에 실패해서 null이 반환됐다면 구현 안한 경우.
		else
		{
			UE_LOG(
				LogTemp,
				Log,
				TEXT("%s님은 수업에 참여할 수 없습니다."),
				*Person->GetName()
			);
		}
	}


	UE_LOG(LogTemp, Log, TEXT("======================="));
}
