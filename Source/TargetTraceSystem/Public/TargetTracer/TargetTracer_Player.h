// Copyright Lim Young.

#pragma once

#include "CoreMinimal.h"
#include "TargetTracer.h"
#include "TargetTracer_Player.generated.h"

/**
 * 
 */
UCLASS()
class TARGETTRACESYSTEM_API UTargetTracer_Player : public UTargetTracer
{
	GENERATED_BODY()

public:
	virtual FVector Trace_Implementation(FTargetTracerContext& Context) override;
};
