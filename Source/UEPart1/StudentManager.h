#pragma once

#include "CoreMinimal.h"

// 전방 선언.
class UStudent;

class UEPART1_API FStudentManager : public FGCObject
{
public:
	FStudentManager(UStudent* InStudent)
		: SafeStudent(InStudent)
	{
	}

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	virtual FString GetReferencerName() const override
	{
		return TEXT("FStudentManager");
	}

	UStudent* GetStudent() const { return SafeStudent; }

private:
	UStudent* SafeStudent = nullptr;
};
