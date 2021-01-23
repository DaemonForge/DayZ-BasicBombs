/*
modded class Hologram
{
	override string ProjectionBasedOnParent()
	{
		BB_PipeBomb item_in_hands = BB_PipeBomb.Cast( m_Player.GetHumanInventory().GetEntityInHands() );

		if ( item_in_hands )
		{
			return "BB_PipeBombPlacing";
		}

		return super.ProjectionBasedOnParent();
	}
	

	//TY CHOPPER FOR THE FIX <3
	override EntityAI PlaceEntity( EntityAI entity_for_placing )
	{
		ItemBase item_in_hands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );

		if ( item_in_hands && item_in_hands.CanMakeGardenplot() )
		{
			Class.CastTo(entity_for_placing, GetGame().CreateObject( m_Projection.GetType(), m_Projection.GetPosition() ));
		}

		if( entity_for_placing.CanAffectPathgraph() )
		{
			entity_for_placing.SetAffectPathgraph( true, false );

			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, entity_for_placing);
		}

		return entity_for_placing;
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{
		ItemBase item_in_hands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );

		if ( item_in_hands && item_in_hands.IsInherited( BB_PipeBomb ))
		{
			SetIsColliding(false);
			return;
		}

		super.EvaluateCollision();
	}

}*/
