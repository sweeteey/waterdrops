package graduation.design.mapper;

import java.util.*;
import org.apache.ibatis.annotations.Param;
import graduation.design.model.Xibie;

public interface XibieMapper {

	public void insertObject(Xibie xibie);

	public void deleteObject(int id);

	public void updateObject(Xibie xibie);

	public Xibie selectObject(int id);

	public List<Xibie> getObjectList(@Param("field") String field,
			@Param("fieldValue") String fieldValue);

}
