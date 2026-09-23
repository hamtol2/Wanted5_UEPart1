// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"

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

	// 클래스 정보 가져오기.
	UClass* ClassRuntime = GetClass();
	UClass* ClassCompile = UMyGameInstance::StaticClass();

	// 두 정보가 같은지 비교(어서트 사용).
	//check(ClassRuntime == ClassCompile);
	//ensure(ClassRuntime == ClassCompile);

	UE_LOG(
		LogTemp,
		Log,
		TEXT("학교를 담당하는 클래스 이름: %s"),
		*ClassRuntime->GetName()
	);

	SchoolName = TEXT("포텐업");

	UE_LOG(LogTemp, Log, TEXT("학교 이름: %s"), *SchoolName);

	UE_LOG(
		LogTemp, 
		Log, 
		TEXT("학교 이름 기본 값: %s"), 
		*GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName
	);

	UE_LOG(LogTemp, Log, TEXT("======================="));

	// 학생/선생님 객체 생성.
	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();

	// 학생 클래스의 Getter 사용.
	Student->SetName(TEXT("학생1"));
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름: %s"), *Student->GetName());

	// 언리얼의 리플렉션 시스템을 활용해서 프로퍼티 정보 가져오기.
	FString CurrentTeacherName;
	FProperty* NameProperty 
		= UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	if (NameProperty)
	{
		// 이름 값 읽어오기.
		NameProperty->GetValue_InContainer(Teacher, &CurrentTeacherName);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름: %s"), *CurrentTeacherName);

		// 새로운 이름 설정.
		FString NewTeacherName(TEXT("장세윤"));
		NameProperty->SetValue_InContainer(Teacher, &NewTeacherName);
		UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름: %s"), *Teacher->GetName());
	}

	UE_LOG(LogTemp, Log, TEXT("======================="));
}
