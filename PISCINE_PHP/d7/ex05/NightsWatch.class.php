<?php
Class NightsWatch implements IFighter
{
	private $array;
	public function recruit($o)
	{
		if ($o instanceof IFighter)
			$this->array[] = $o;
	}
	public function fight()
	{
		foreach ($this->array as $key => $value){
			$value->fight();
		}
	}
}
?>