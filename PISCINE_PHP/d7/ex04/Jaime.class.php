<?php
Class Jaime extends Lannister
{
	public function with($o)
	{
		if (get_parent_class($o) !== 'Lannister')
			return ("Let's do this.");
		else if (get_class($o) === "Cersei")
			return ("With pleasure, but only in a tower in Winterfell, then.");
		else
			return ("Not even if I'm drunk !");
	}
}
?>