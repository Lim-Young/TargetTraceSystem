// Copyright Lim Young.


#include "TargetTracer/TargetTracer_ActorLocation.h"

FVector UTargetTracer_ActorLocation::Trace_Implementation(FTargetTracerContext& Context)
{
	if (!IsValid(TargetActor))
	{
		return FVector::ZeroVector;
	}

	return TargetActor->GetActorLocation();
}
