// Copyright Lim Young.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TargetTraceSystemStatics.generated.h"

/**
 * 
 */
UCLASS()
class TARGETTRACESYSTEM_API UTargetTraceSystemStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION()
	static FVector GetTargetPredictedLocation(const FVector& SourceLocation, const AActor* Actor, const float LeadTargetProjectileVelocity,
	                                    const bool bLeadTargetIgnoreZVelocity = false);
};
