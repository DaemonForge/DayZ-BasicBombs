modded class ActionDeployObject: ActionContinuousBase
{		
	override void MoveEntityToFinalPosition( ActionData action_data, vector position, vector orientation )
	{
		BB_PipeBomb bomb = BB_PipeBomb.Cast( action_data.m_MainItem);
		if ( bomb ) {
			vector OffsetOrientation = "0 0 -90";
			orientation = orientation + OffsetOrientation;
			vector OffsetPosition = "0 0.02 0";
			position = position + OffsetPosition;
		}
		super.MoveEntityToFinalPosition( action_data, position, orientation );
	}
};