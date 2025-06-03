// Copyright Lim Young.

#pragma once

#include "CoreMinimal.h"
#include "TargetTracer.h"
#include "TargetTracer_ActorLocation.generated.h"

/**
 * 
 */
UCLASS()
class TARGETTRACESYSTEM_API UTargetTracer_ActorLocation : public UTargetTracer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "TargetTracer|ActorLocation",
		meta = (DisplayName = "Actor Location", ToolTip = "The location of the actor to trace."))
	TObjectPtr<AActor> TargetActor = nullptr;

	virtual FVector Trace_Implementation(FTargetTracerContext& Context) override;
};
