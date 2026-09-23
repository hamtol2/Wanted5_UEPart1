// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"

UStudent::UStudent()
{
	// 값 설정.
	Name = TEXT("학생");
}

void UStudent::DoLesson()
{
	ILessonInterface::DoLesson();
	UE_LOG(
		LogTemp,
		Log,
		TEXT("%s님이 수업을 수강합니다."),
		*Name
	);
}
