#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Person.generated.h"

UCLASS()
class UEPART1_API UPerson : public UObject
{
	GENERATED_BODY()

public:
	UPerson();

	// Getter/Setter.
	inline const FString& GetName() const { return Name; }
	inline void SetName(const FString& InName) { Name = InName; }

protected:
	// 관리 받는 속성으로 선언.
	UPROPERTY()
	FString Name;
};
