package graduation.design.mapper;

import java.util.*;
import org.apache.ibatis.annotations.Param;
import graduation.design.model.Gongao;

public interface GongaoMapper {

	public void insertObject(Gongao gongao);

	public void deleteObject(int id);

	public void updateObject(Gongao gongao);

	public Gongao selectObject(int id);

	public List<Gongao> getObjectList(@Param("field") String field,
			@Param("fieldValue") String fieldValue);

}
