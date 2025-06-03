// Copyright Lim Young.


#include "TargetTraceSystemComponent.h"


UTargetTraceSystemComponent::UTargetTraceSystemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTargetTraceSystemComponent::AddOrUpdateTarget(const FName TargetName, const FVector TargetLocation)
{
	if (TargetMap.Contains(TargetName))
	{
		TargetMap[TargetName] = TargetLocation;
	}
	else
	{
		TargetMap.Add(TargetName, TargetLocation);
	}
}

void UTargetTraceSystemComponent::RemoveTarget(const FName TargetName)
{
	if (TargetMap.Contains(TargetName))
	{
		TargetMap.Remove(TargetName);
	}
}

bool UTargetTraceSystemComponent::GetTargetLocation(const FName TargetName, FVector& TargetLocation)
{
	if (!TargetTracers.Contains(TargetName))
	{
		return false;
	}

	TargetTracerContext.Reset(GetOwner());
	AddOrUpdateTarget(TargetName, TargetTracers[TargetName]->Trace(TargetTracerContext));
#if WITH_EDITOR
	if (bDebug)
	{
		DrawDebug(TargetName);
	}
#endif
	TargetLocation = TargetMap[TargetName];
	return true;
}

#if WITH_EDITOR
void UTargetTraceSystemComponent::DrawDebug(const FName TargetName) const
{
	if (!TargetMap.Contains(TargetName))
	{
		return;
	}

	DrawDebugSphere(GetWorld(), TargetMap[TargetName], 50.0f, 12, FColor::Red, false, 2.0f, 0, 1.0f);
	DrawDebugString(GetWorld(), TargetMap[TargetName] + FVector(0, 0, 50), TargetName.ToString(), nullptr,
	                FColor::White, 2.0f, true);
}
#endif
