// Copyright Lim Young.

#pragma once

#include "CoreMinimal.h"
#include "TargetTracer.h"
#include "Components/ActorComponent.h"
#include "TargetTraceSystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TARGETTRACESYSTEM_API UTargetTraceSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UTargetTraceSystemComponent();

private:
	TMap<FName, FVector> TargetMap;

	UPROPERTY(Transient)
	FTargetTracerContext TargetTracerContext;

protected:
	UPROPERTY(Instanced, EditAnywhere, Category="Target Trace System")
	TMap<FName, TObjectPtr<UTargetTracer>> TargetTracers;


	UFUNCTION(BlueprintCallable, Category="Target Trace System")
	void AddOrUpdateTarget(const FName TargetName, FVector TargetLocation);

	UFUNCTION(BlueprintCallable, Category="Target Trace System")
	void RemoveTarget(const FName TargetName);

public:
	UFUNCTION(BlueprintCallable, Category="Target Trace System")
	bool GetTargetLocation(const FName TargetName, FVector& TargetLocation);


#if WITH_EDITORONLY_DATA

protected:
	UPROPERTY(EditAnywhere, Category="Target Trace System")
	bool bDebug = false;

	void DrawDebug(const FName TargetName) const;
#endif
};
