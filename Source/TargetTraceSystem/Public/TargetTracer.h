// Copyright Lim Young.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TargetTracer.generated.h"

USTRUCT(BlueprintType)
struct TARGETTRACESYSTEM_API FTargetTracerContext
{
	GENERATED_BODY()

	UPROPERTY()
	AActor* OwnerActor = nullptr;

	FTargetTracerContext()
	{
	}

	explicit FTargetTracerContext(AActor* InOwnerActor) : OwnerActor(InOwnerActor)
	{
	}

	void Reset(AActor* InOwnerActor)
	{
		OwnerActor = InOwnerActor;
	}
};

/**
 * 
 */
UCLASS(Abstract, DefaultToInstanced, EditInlineNew, CollapseCategories)
class TARGETTRACESYSTEM_API UTargetTracer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "TargetTraceSystem|Tracer")
	FVector Trace(FTargetTracerContext& Context);
};
