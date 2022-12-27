package system.common.util;

import graduation.design.model.User;

import org.hibernate.cfg.Configuration;
import org.hibernate.tool.hbm2ddl.SchemaExport;


public class ExportDB {

	public static void main(String[] args) {

		Configuration cfg = new Configuration().configure();

		SchemaExport export = new SchemaExport(cfg);

		export.create(true, true);
		User util = new User();
		util.setS_0("admin");
		util.setS_1("admin");
		util.setS_2("admin");
		util.setS_11("admin");
		new DBUtil().saveUser(util);

	}
}
