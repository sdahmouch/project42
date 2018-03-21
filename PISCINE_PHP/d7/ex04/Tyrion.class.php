<?php
Class Tyrion extends Lannister
{
	public function with($o)
	{
		if (get_parent_class($o) !== 'Lannister')
			return ("Let's do this.");
		return ("Not even if I'm drunk !");
	}
}
?>